/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e3+1;
const int M =51;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int c,n,m;
ll dp[N][M];
void solve(){
    
    cin>>c>>n>>m;
    for(int i = 1; i <= n; i++) {
        // n(log2(c) + m)
        ll x; cin>>x;
        int k = 0;
        while(x <= c) {
            k++;
            x *= 2ll;
        }
        dp[i][0] = 1;
        for(int j = 1; j < M; j++) {
            dp[i][j] = dp[i][j-1];
            if(j >= k) dp[i][j] *= 2ll;
        }
    }
    for(int i = 1; i <= m; i++) {
        ll ans = 0;
        int x; cin>>x;
        for(int j = 1; j <= n; j++) {
            ans += dp[j][x];
        }
        cout << ans << nl;
    }
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

