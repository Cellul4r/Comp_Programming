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
ll dp[N][11][2];
void solve(){
    
    int n,k; cin>>n>>k;
    vector<ll> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i]>>b[i];
    }
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= 10; j++) {
            for(int k = 0; k < 2; k++) {
                dp[i][j][k] = -LINF;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            if(dp[i-1][j][0] != -LINF) {
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][0] + a[i]);
            }
            if(dp[i-1][j][1] != -LINF) {
                dp[i][j][0] = max(dp[i][j][0], dp[i-1][j][1] + a[i]);
            }

            if(dp[i-1][j][1] != -LINF) {
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j][1] + b[i]);
            }
            if(j - 1 >= 0 && dp[i-1][j-1][0] != -LINF) {
                dp[i][j][1] = max(dp[i][j][1], dp[i-1][j-1][0] + b[i]);
            }
        }
    }
    ll ans = -LINF;
    for(int i = 0; i <= k; i++) {
        for(int j = 0; j < 2; j++) {
            ans = max(ans, dp[n][i][j]);
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

