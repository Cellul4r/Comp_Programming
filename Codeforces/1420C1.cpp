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
void solve(){
    
    int n,q; cin>>n>>q;
    assert(q == 0);
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    //  + 1 - 2 + 5 - 4 + 3 - 6 + 7
    vector<vector<ll>> dp(n+1, vector<ll>(2, -LINF));
    dp[1][0] = a[1];
    dp[1][1] = -a[1];
    ll mx1 = dp[1][0], mx2 = dp[1][1];
    for(int i = 2; i <= n; i++) {
        dp[i][0] = max(a[i], a[i] + mx2);
        dp[i][1] = max(-a[i], -a[i] + mx1);
        //cerr << dp[i][0] << " " << dp[i][1] << nl;
        mx1 = max(mx1, dp[i][0]);
        mx2 = max(mx2, dp[i][1]);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, max(dp[i][0],dp[i][1]));
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

