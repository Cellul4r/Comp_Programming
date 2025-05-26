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

vector<pair<int,ll>> adj[N];
int n,m;
int a[N];
bool go(int x) {

    vector<int> dp(n,-INF);
    dp[0] = 0;
    for(int u = 0; u < n; u++) {
        dp[u] = min(dp[u]+a[u], x);
        for(auto &vw : adj[u]) {
            int v = vw.first;
            if(dp[u] >= vw.second) {
                dp[v] = max(dp[v],dp[u]);
            }
        }
    }

    return dp[n-1] >= 0;
}
void solve(){
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        adj[i].clear();
    }
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    int ans = -1;
    int l = 0, r = 1e9+5;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        //cerr << mid << nl;
        if(go(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << nl;
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

