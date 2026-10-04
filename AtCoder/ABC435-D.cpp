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
const int N =3e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
vector<int> adj[N];
bool vis[N];
int n,m;
void dfs(int u) {
    if(vis[u]) return;
    vis[u] = true;
    for(auto &v : adj[u]) {
        if(!vis[v]) dfs(v);
    }
}
void solve(){
    
    cin>>n>>m;
    for(int i = 1; i <= m; i++) {
        int u,v; cin>>u>>v;
        adj[v].push_back(u);
    }
    int q; cin>>q;
    for(int i = 1; i <= q; i++) {
        int type,u; cin>>type>>u;
        if(type == 1) {
            dfs(u); 
        } else {
            cout << (vis[u] ? "Yes" : "No") << nl;
        }
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

