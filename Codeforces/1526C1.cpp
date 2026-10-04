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
    vector<ll> a(n+1);    
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    // dp[i][j] the maximum hp we can get such that we consider the posion from 1 to i and currently eat j poisons
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, -LINF));
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < n; j++) {
            // not eat this poison
            dp[i][j] = max(dp[i][j],dp[i-1][j]);

            // eat this poison
            if(dp[i-1][j] >= 0) {
                dp[i][j+1] = max(dp[i][j+1], dp[i-1][j] + a[i]);
            }
        }
        /*
        for(int j = 0; j <= n; j++) {
            cout << (dp[i][j] == -LINF ? -100 : dp[i][j])  << " ";
        }
        cout << nl;
        */
    }
    ll ans = 0;
    for(int j = 1; j <= n; j++) {
        for(int i = 1; i <= n; i++) {
            if(dp[i][j] >= 0) {
                ans = j;
                break;
            }
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

