/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n;
string a,b;
map<string, vector<string>> adj;
map<string, int> depthA, depthB;
set<string> all;
int dfs1(string u) {

    if(u == a) {
        return depthA[a] = 0;
    }
    int d = INF;
    for(auto &v : adj[u]) {
        d = min(d,1 + dfs1(v));
    }
    return depthA[u] = d;
}

int dfs2(string u) {

    if(u == b) {
        return depthB[b] = 0;
    }

    /*if(depthB.find(u) != depthB.end()) {
        return depthB[u];
    }*/
    int d = INF;
    for(auto &v : adj[u]) {
        d = min(d,1 + dfs2(v));
    }
    return depthB[u] = d;
}
void solve(){
    
    cin>>n>>a>>b;
    for(int i = 0; i < n; i++) {
        string u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        all.insert(u);
        all.insert(v);
    }

    for(auto &u : adj) {
        dfs1(u.first);
        dfs2(u.first);
    }

    /*for(auto &u : depthA) {
        cout << u.first << " " << u.second << nl;
    }
    cout << nl;
    for(auto &u : depthB) {
        cout << u.first << " " << u.second << nl;
    }*/
    for(auto &u : all) {
        if(depthA.find(u) == depthA.end()) depthA[u] = INF;
        if(depthB.find(u) == depthB.end()) depthB[u] = INF;
    }
    // is it your mother, grand-mother, great-grand-mother?
    // is it your sibling?
    for(auto &name : all) {
        if(depthA[name] == INF || depthB[name] == INF) continue;
        if(depthA[name] == 0) {
            cout << a << " is the ";
            for(int i = 0; i < depthB[name] - 2; i++) {
                cout << "great-";
            }
            if(depthB[name] > 1) {
                cout << "grand-";
            }
            cout << "mother " << "of " << b;
            return;
        } else if(depthB[name] == 0) {
            cout << b << " is the ";
            for(int i = 0; i < depthA[name] - 2; i++) {
                cout << "great-";
            }
            if(depthA[name] > 1) {
                cout << "grand-";
            }
            cout << "mother " << "of " << a;
            return;
        } else if(depthA[name] == 1 && depthB[name] == 1) {
            cout << "SIBLINGS";
            return;
        }
    }
    for(auto &name : all) {
        if(depthA[name] == INF || depthB[name] == INF) continue;
        if(depthA[name] == 1) {
            cout << a << " is the ";
            for(int i = 0; i < depthB[name] - 2; i++) {
                cout << "great-";
            }
            cout << "aunt of " << b;
            return;
        } else if(depthB[name] == 1) {
            cout << b << " is the ";
            for(int i = 0; i < depthA[name] - 2; i++) {
                cout << "great-";
            }
            cout << "aunt of " << a;
            return;
        }
    }
    // is it your cousin?
    for(auto &name : all) {
        if(depthA[name] == INF || depthB[name] == INF) continue;
        cout << "COUSINS";
        return;
    }
    // no others choice
    cout << "NOT RELATED";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("family.in", "r", stdin);
    freopen("family.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

