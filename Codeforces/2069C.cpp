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
const ll LINF = 998244353;

void setIO(string);
void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(4, 0));
    // dp[i][..] # of subseq from index 1 to i
    // dp[i][1] # of subseq ending with .... 1 or 1
    // dp[i][2] # of subseq with 1 22...
    // dp[i][3] # of subseq with complete 1 22...22 3
    for(int i = 1; i <= n; i++) {
        if(a[i] == 1) {
            dp[i][1] = (dp[i-1][1] + 1ll) % LINF;
            dp[i][2] = dp[i-1][2];
            dp[i][3] = dp[i-1][3];
        } else if(a[i] == 2) {
            dp[i][2] = ((2ll * dp[i-1][2] % LINF) + dp[i-1][1]) % LINF;
            dp[i][1] = dp[i-1][1];
            dp[i][3] = dp[i-1][3];
        } else {
            dp[i][1] = dp[i-1][1];
            dp[i][2] = dp[i-1][2];
            dp[i][3] = (dp[i-1][2] + dp[i-1][3]) % LINF;
        }
    }
    
    cout << dp[n][3] << nl;
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

