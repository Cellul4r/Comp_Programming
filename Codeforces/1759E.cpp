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
    
    int n;
    ll h; cin>>n>>h;
    // we must eat all ai <= h currently and absorb it
    // then what can we do if j > i such that aj > h, we must use green or blue serum??
    // claim if we can eat ai then all j such that aj < ai, we can also eat all aj before we eat ai
    // but the thing we should use green or blue or what???
    // green has 2, blue 1
    // the possible is *2, *2*2, *2*3, *3, *2*2*3
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    // dp[i][j][k] the maximum/minimum? power h we can have during we absorb i astro, use j green, k blue
    ll dp[n+1][3][2];
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 2; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    dp[0][0][0] = h;
    dp[0][0][1] = h * 3ll;
    dp[0][1][0] = h * 2ll;
    dp[0][1][1] = h * 6ll;
    dp[0][2][0] = h * 4ll;
    dp[0][2][1] = h * 12ll;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= 2; j++) {
            for(int k = 0; k <= 1; k++) {
                ll now = dp[i][j][k]; 
                if(now == -1) continue;
                // use more green, blue
                // drink green potion
                if(j < 2) {
                    dp[i][j+1][k] = max(dp[i][j+1][k], now * 2ll);
                }
                // drink more blue potion
                if(k < 1) {
                    dp[i][j][k+1] = max(dp[i][j][k+1], now * 3ll);
                }
                if(a[i+1] < now) {
                    dp[i+1][j][k] = max(dp[i+1][j][k], now + a[i+1] / 2ll);
                    ans = max(ans, i+1);
                }
                //cout << dp[i][j][k] << " ";
            }
        }
        //cout << nl;
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

