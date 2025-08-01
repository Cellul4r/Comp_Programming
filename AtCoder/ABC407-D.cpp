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
const int N = 21;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n,m;
ll a[N][N];
ll dp[1<<20];
int conv(int i, int j) {
    return (i - 1) * m + j - 1; 
}

ll cal(int mask) {
    ll now = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mask & (1 << conv(i,j))) continue;
            now ^= a[i][j];
        }
    }
    return now;
}
ll recur(int mask) {
    //cerr << r << " " << c << nl;
    if(dp[mask] != -1) {
        return dp[mask];
    }
    ll ans = cal(mask);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(mask & (1 << conv(i,j))) continue;
            int nmask = mask | (1 << conv(i,j));
            if(j < m && !(mask & (1 << conv(i,j+1)))) {
                ans = max(ans, recur(nmask | (1 << conv(i,j+1))));
            }
            if(i < n && !(mask & (1 << conv(i+1,j)))) {
                ans = max(ans, recur(nmask | (1 << conv(i+1,j))));
            }
        }
    }
    return dp[mask] = ans;
}
void solve(){

    cin>>n>>m;
    for(int mask = 0; mask < (1 << (n*m)); mask++) {
        dp[mask] = -1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin>>a[i][j];
        }
    }
    ll ans = recur(0);
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    //cin>>t;
    while(t--)solve();

    return 0;
}

