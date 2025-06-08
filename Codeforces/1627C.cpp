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

void setIO(string);
vector<int> adj[N];
int deg[N], ans[N];
map<pi,int> weight;
void dfs(int u, int p, int w) {

    int k = w;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        int uu = u, vv = v;
        if(uu > vv) swap(uu,vv);
        ans[weight[make_pair(uu,vv)]] = k;
        k ^= 1;
        dfs(v,u,k);
    }
}
void solve(){
    
    int n;
    cin>>n;
    weight.clear();
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        deg[i] = 0;
    }
    for(int i = 0; i < n - 1; i++) {
        int u,v;
        cin>>u>>v;
        if(u > v) swap(u,v);
        weight[make_pair(u,v)] = i;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    for(int i = 1; i <= n; i++) {
        if(deg[i] >= 3) {
            cout << -1 << nl;
            return;
        }
    }
    
    dfs(1,0,2);
    for(int i = 0; i < n - 1; i++) {
        cout << ans[i] << " ";
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

