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

void solve(){
    
    int n,m;
    cin>>n>>m;

    vector<int> a(n+1, n);
    vector<int> dp(n+1, INF);
    for(int i = 0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        if(v > u) {
            a[u] = min(a[u], v - 1);
        } else {
            a[v] = min(a[v], u - 1);
        }
    }

    ll ans = 1;
    dp[n] = 1;
    for(int i = n - 1; i >= 1; i--) {
        dp[i] = min(a[i] - i + 1, 1 + dp[i+1]);
        ans += dp[i];
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

