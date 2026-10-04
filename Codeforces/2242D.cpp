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
    
    string a,b; cin>>a>>b;
    int n = a.size(), m = b.size();

    vector<int> pa(n+1), pb(m+1);
    for(int i = 1; i <= n; i++) {
        pa[i] = pa[i-1] + (a[i-1] - '0');
        pa[i] %= 10;
    }
    for(int i = 1; i <= m; i++) {
        pb[i] = pb[i-1] + (b[i-1] - '0');
        pb[i] %= 10;
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1,0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(pa[i] == pb[j]) {
                dp[i][j] = dp[i-1][j-1] + 1; 
            } else if(i < n && j < m) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << (dp[n][m] == 0 ? -1 : dp[n][m]) << nl;
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

