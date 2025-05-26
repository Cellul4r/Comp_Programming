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
    
    int n;
    cin>>n;
    vector<int> a(n);
    vector<ll> dp(n);
    for(auto &x : a) {
        cin>>x;
    }
    for(int i = 1; i <= n - 2; i++) {
        dp[i] = (i - 2 >= 0 ? dp[i-2] : 0ll) + 1ll * max(0, max(a[i-1],a[i+1]) - a[i] + 1);
        if(i % 2 == 0) dp[i] = min(dp[i],dp[i-1]);
    }
    if(n & 1) {
        cout << dp[n-2] << nl;
    } else {
        cout << min(dp[n-2], dp[n-3]) << nl;
    }
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

    cin>>t;
    while(t--)solve();

    return 0;
}

