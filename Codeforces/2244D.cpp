/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n,m; cin>>n>>m;
    vector<ll> a(n+1);
    vector<bool> can(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    for(int i = 1; i <= m; i++) {
        int x; cin>>x;
        can[x] = 1;
    }

    vector<vector<ll>> dp(n+1, vector<ll>(2,0));
    vector<vector<ll>> dp2(n+1, vector<ll>(2,0));
    for(int i = 1; i <= n; i++) {
        dp[i][0] = a[i] + max(dp[i-1][0], dp[i-1][1]);
        dp2[i][0] = a[i] + min(dp2[i-1][0], dp2[i-1][1]);
        if(!can[i]) {
            dp[i][1] = a[i] + max(dp[i-1][0], dp[i-1][1]);
            dp2[i][1] = a[i] + min(dp2[i-1][0], dp2[i-1][1]);
        } else {
            dp[i][1] = -a[i] - min(dp2[i-1][0], dp2[i-1][1]);
            dp2[i][1] = -a[i] - max(dp[i-1][0], dp[i-1][1]);
        }
        //cout << dp[i][0] << " " << dp[i][1] << nl;
    }
    cout << max(dp[n][0], dp[n][1]) << nl;
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

