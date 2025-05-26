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
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

vector<int> adj[N];
int par[N], a[N];
ll dp1[N], dp2[N];
void dfs1(int u, int p) {
    par[u] = p;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        dfs1(v, u);
    }
}

void dfs2(int u, int p) {
    dp1[u] = max(1ll * a[u], 1ll * a[u] - dp2[p]);
    dp2[u] = min(1ll * a[u], 1ll * a[u] - dp1[p]);
    for(auto &v : adj[u]) {
        if(v == p) continue;
        dfs2(v,u);
    }
}
void solve(){
    
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];         
        adj[i].clear();
        dp1[i] = 0;
        dp2[i] = LINF;
    }
    for(int i = 0; i < n - 1; i++) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    //dfs1(0,0);
    /*for(int i=0;i<n;i++) {
        cerr << par[i] << " ";
    }*/

    dp1[0] = dp2[0] = a[0];
    dfs2(0,0);
    for(int i = 0; i < n; i++) {
        cout << dp1[i] << " ";
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

