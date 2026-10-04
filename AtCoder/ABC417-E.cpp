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
const int N =1e3+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
vector<int> path;
vector<int> adj[N];
bool vis[N];
int n,m,x,y;
bool dfs(int u) {
    if(u == y) {
        return true;
    }
    vis[u] = true;
    int mn = INF;
    for(auto &v : adj[u]) {
        if(vis[v]) continue;
        mn = min(mn, v);
    }

    if(mn == INF) return false;
    path.push_back(mn);
    if(!dfs(mn)) {
        vis[u] = false;
        path.pop_back();
    }

    return true;
}
void solve(){
    
    path.clear();
    cin>>n>>m>>x>>y;
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        vis[i] = false;
    }

    for(int i = 0 ;i <m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    path.push_back(x);
    dfs(x);
    path.push_back(y);
    for(auto &k : path) cout << k << " ";
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

