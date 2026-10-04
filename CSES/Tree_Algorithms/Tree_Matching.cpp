/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n;
vector<int> adj[N];
int dp[N][2];
int dfs(int u, int p, bool used) {
    for(auto &v : adj[u]) {
        if(v == p) continue;
        dp[u][0] += dfs(v, u, false);
    }
    dp[u][1] = dp[u][0];

    if(used) return dp[u][1];

    for(auto &v : adj[u]) {
        if(v == p) continue;
        // this is not correct formulation
        dp[u][0] = max(dp[u][0], 1 + dp[u][1] + dp[v][1] - dp[v][0]);
    }
    return dp[u][0];
}
void solve(){
    
    cin>>n;
    for(int i = 0; i < n - 1; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << dfs(1,0,false);
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

