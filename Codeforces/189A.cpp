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
ll a[3];
ll dp[4001];
ll recur(int i) {
    if(i < 0) return -LINF;
    if(i == 0) return 0ll; 
    if(dp[i] != -1) return dp[i];
    
    ll mx = -LINF;
    for(int j = 0; j < 3; j++) {
        ll nxt = recur(i - a[j]);
        if(nxt != -LINF) {
            mx = max(mx, nxt + 1ll);
        }
    }
    return dp[i] = mx;
}
void solve(){
    
    int n;
    cin>>n;
    // using x a[0], y a[1] thus (n - x*a[0] - y*a[1] ) mod a[2] = 0
    for(int i = 0; i < 3; i++) {
        cin>>a[i];
    }
    for(int i = 0; i <= n; i++) {
        dp[i] = -LINF;
    }
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            if(i < a[j]) continue;
            if(dp[i-a[j]] == -LINF) continue;
            dp[i] = max(dp[i], 1 + dp[i-a[j]]);
        }
    }
    cout << dp[n];
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

