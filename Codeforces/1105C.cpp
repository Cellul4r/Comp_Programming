/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const ll INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    int n;
    ll l,r; cin>>n>>l>>r;
    // choose the number of 1s
    // dp[i][j] -> the number of ways from the array 1..to i such that current S % 3 = j
    // 3, 6, 9, 12, 15
    auto f = [&](ll m) {
        if(r < m) return 0ll;
        ll rr = (r - m) / 3ll + 1;
        ll ll = (l-1-m >= 0 ? (l - 1 - m) / 3ll + 1 : 0ll);
        return rr - ll;
    };
    vector<ll> cur{f(3), f(1), f(2)};
    vector<vector<ll>> dp(n+1, vector<ll>(3, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                dp[i][j] = (dp[i][j] + cur[k] * dp[i-1][(j-k+3)%3] % INF) % INF;
            }
            //cout << dp[i][j] << " ";
        }
        //cout << nl;
    }
    cout << dp[n][0];
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

