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

void setIO(string);
vector<pi> adj[N];
bool vis[N];
void dfs(int u, int& mask) {
    vis[u] = true;
    for(auto &vw : adj[u]) {
        if(mask & vw.second) {
            continue;
        }
        if(vis[vw.first]) continue;
        dfs(vw.first, mask);
    }
}
void solve(){
    
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    int ans = 0;
    int mask = 0;
    for(int i = 30; i >= 0; i--) {
        for(int j = 0; j < n; j++) vis[j]= false;
        mask |= (1 << i);
        dfs(0,mask);
        if(!vis[n-1]) {
            ans |= (1 << i);
            mask ^= (1 << i);
        }
    }
    cout << ans;
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

