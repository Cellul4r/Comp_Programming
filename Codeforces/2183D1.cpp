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
vector<int> adj[N];
int depth[N];
int cnt[N];
void dfs(int u, int p) {
    for(auto &v : adj[u]) {
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}
void solve(){
    
    int n; cin>>n;
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        depth[i] = 0;
        cnt[i] = 0;
    }
    for(int i = 1; i <= n - 1; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0);
    for(int i = 1; i <= n; i++) {
        cnt[depth[i]]++;
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, cnt[i]);
    }
    ans = max(ans, (int)adj[1].size() + 1);
    for(int i = 2; i <= n; i++) {
        ans = max(ans, (int)adj[i].size());
    }
    cout << ans << nl;
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

