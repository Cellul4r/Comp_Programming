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
const int N =1e3+1;
const ll INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n,m;
int dp[N][N];
void solve(){
    
    cin>>n>>m;
    for(int i = 1; i <= min(n,m); i++) {
        ll k = 1ll * dp[n][i] * dp[m][i] % INF;
        if(k == 0) break;
        cout << k << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    dp[0][0] = 1;
    for(int i = 1; i < N; i++) {
        dp[i][0] = dp[i][N-1] = 1;
        for(int j = 1; j < N - 1; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            dp[i][j] %= INF;
        }
    }
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

