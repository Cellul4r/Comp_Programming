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
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int dp[20][N];
void solve(){
    
    int l,r;
    cin>>l>>r;
    int ans = INF;
    for(int i = 0; i < 20; i++) {
        if(dp[i][r] - dp[i][l-1] > 0) {
            ans = min(ans, r - l + 1 - (dp[i][r] - dp[i][l-1]));
        }
    }

    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < N; j++) {
            if((1 << i) & j) {
                dp[i][j] = 1;
            }
        }
        for(int j = 1; j < N; j++) {
            dp[i][j] += dp[i][j-1];
        }
    }
    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

