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
const int N =505;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);

int par[N], depth[N];
int cur = 0;
map<string,int> save;
int check(string s) {
    if(save.count(s)) {
        return save[s];
    }
    save[s] = cur++;
    return cur-1; 
}
int findRoot(int u) {
    while(u != par[u]) {
        u = par[u];
    }
    return u;
}
void solve(){

    for(int i = 0; i < N; i++) {
        par[i] = i;
    }
    string a,b;
    while(cin>>a>>b) {
        if(a == "no.child") break;
        int u = check(a), v = check(b);
        par[u] = v;
    }

    for(int i = 0; i < cur; i++) {
        int u = i;
        while(u != par[u]) {
            depth[i]++;
            u = par[u];
        }
    }

    while(cin>>a>>b) {
        if(save.count(a) == 0 || save.count(b) == 0) {
            cout << "no relation\n";
            continue;
        }
        int u = save[a], v = save[b];
        if(findRoot(u) != findRoot(v)) {
            cout << "no relation\n";
            continue;
        }

        int du = depth[u], dv = depth[v];
        int uu = u, vv = v;
        while(du > dv) {
            du--;            
            u = par[u];
        }
        while(dv > du) {
            dv--;
            v = par[v];
        }

        while(u != v) {
            u = par[u];
            v = par[v];
        }

        if(u == uu) {
            // u is parent    
            int d = depth[vv] - depth[uu];
            for(int i = 0; i < d - 2; i++) cout << "great ";
            if(d > 1) cout << "grand ";
            cout << "parent";
        } else if(u == vv) {
            int d = depth[uu] - depth[vv]; 
            for(int i = 0; i < d - 2; i++) cout << "great ";
            if(d > 1) cout << "grand ";
            cout << "child";
        } else if(depth[uu] - depth[u] == 1 && depth[vv] - depth[u] == 1) {
            cout << "sibling";
        } else {
            int n = depth[uu] - depth[u];
            int m = depth[vv] - depth[u];
            cout << min(n,m) - 1 << " cousin";
            if(abs(n-m) > 0) cout << " removed " << abs(n-m);
        }
        cout << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

