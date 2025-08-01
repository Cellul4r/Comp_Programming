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
    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    for(int i = 0; i < m; i++) {
        cin>>b[i];
    }


    auto f = [&](int k) {
        vector<vector<int>> dp(n+1, vector<int>(2));
        for(int i = 1; i <= n; i++) {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1];
            if(dp[i][0] < m && b[dp[i][0]] <= k) dp[i][1] = max(dp[i][1], dp[i][0] + 1);
            if(dp[i][0] < m && b[dp[i][0]] <= a[i-1]) dp[i][0]++;
            if(dp[i][1] < m && b[dp[i][1]] <= a[i-1]) dp[i][1]++;
        }
        if(dp[n][0] < m && k >= b[dp[n][0]]) dp[n][1] = max(dp[n][1], dp[n][0] + 1);
        return dp[n][1] == m;
    };

    int l = 0, r = 1e9;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(f(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int ans = (f(l) ? l : -1);
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

