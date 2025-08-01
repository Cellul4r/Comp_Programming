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
const int N =5001;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n,q;
int c[N];
int w[N];
ll pre[N];
ll suff[N];
ll dp[N][N];
ll recur(int u, int v, vector<bool> vis) {
    if(u == v) {
        return 0;
    }

    if(~dp[u][v]) return dp[u][v];
    //cerr << u << " " << v << nl;
    vis[u] = true;
    ll ans = c[u] * labs(pre[v] - pre[u]);
    for(int k = 0; k < n; k++) {
        if(vis[k]) continue;
        ans = min(ans, c[u] * labs(pre[k] - pre[u]) + recur(k,v, vis)); 
    }
    return dp[u][v] = ans;
}
void solve(){
    
    memset(dp, -1, sizeof dp);
    cin>>n>>q;
    for(int i = 1; i < n; i++) {
        cin>>w[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>c[i];
    }
    pre[0] = w[0];
    for(int i = 1; i < n; i++) {
        pre[i] = pre[i-1] + w[i]; 
    }
    for(int i = 0; i < q; i++) {
        int u,v;
        cin>>u>>v;
        vector<bool> vis(n);
        ll ans = recur(u,v,vis);
        cout << ans << nl;
    }
}
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

