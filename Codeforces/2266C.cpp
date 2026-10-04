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
    
    int n; cin>>n;
    string s; cin>>s;

    // one operation can change the bit in s only 1 positions
    // trivially
    // 00000 -> 0 operations
    // 11111 -> 0 operations
    // else?
    // 000111 -> 0 operations
    // 1110000 -> min(one, zero)
    vector<vector<int>> dp(n, vector<int>(2,INT_MAX));
    if(s[0] == '0') {
        dp[0][0] = 0;
    } else {
        dp[0][1] = 0;
    }
    for(int i = 1; i < n; i++) {
        // previous is 0
        // this can be 1 or 0
        // make this 0
        if(s[i] == '0') {
            dp[i][0] = min(dp[i][0], dp[i-1][0]);
        } else {
            if(dp[i-1][0] != INT_MAX) {
                dp[i][0] = min(dp[i][0], dp[i-1][0] + 1);
            }
        }
        // make this 1
        if(s[i] == '0') {
            if(dp[i-1][0] != INT_MAX) {
                dp[i][1] = min(dp[i][1], dp[i-1][0] + 1);
            }
        } else {
            dp[i][1] = min(dp[i][1], dp[i-1][0]);
        }
        // previous is 1
        // this must be only 1
        if(s[i] == '0') {
            // must change the op
            if(dp[i-1][1] != INT_MAX) {
                dp[i][1] = min(dp[i][1],1 + dp[i-1][1]);
            }
        } else {
            dp[i][1] = min(dp[i][1],dp[i-1][1]);
        }
        //cout << dp[i][0] << " " << dp[i][1] << nl;
    }
    cout << min(dp[n-1][0], dp[n-1][1]) << nl;
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

