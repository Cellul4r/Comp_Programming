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
    
    int n; cin>>n;
    vector<vector<ll>> a(n+1);

    for(int i = 0; i < 2 * n; i++) {
        int x; cin>>x;
        a[x].push_back(i);
    }

    vector<vector<ll>> dp(n+1,vector<ll>(2,LINF));
    dp[1][0] = dp[1][1] = a[1][0] + a[1][1];
    for(int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i][0], dp[i-1][0] + abs(a[i][0] - a[i-1][0]) + abs(a[i][1] - a[i-1][1]));
        dp[i][0] = min(dp[i][0], dp[i-1][1] + abs(a[i][0] - a[i-1][1]) + abs(a[i][1] - a[i-1][0]));

        dp[i][1] = min(dp[i][1], dp[i-1][0] + abs(a[i][1] - a[i-1][0]) + abs(a[i][0] - a[i-1][1]));
        dp[i][1] = min(dp[i][1], dp[i-1][1] + abs(a[i][1] - a[i-1][1]) + abs(a[i][0] - a[i-1][0]));
    }

    cout << min(dp[n][0],dp[n][1]);
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

