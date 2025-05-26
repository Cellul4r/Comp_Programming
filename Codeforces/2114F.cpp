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
const int N =1e6+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
void solve(){

    int x,y,k;
    cin>>x>>y>>k;
    int gcd_ = gcd(x,y);
    x /= gcd_;
    y /= gcd_;

    // dp[i] number of minimum operation to make to i
    auto findd = [&](int x) {
        vector<int> dp(x+1,INF);
        dp[1] = 0;
        for(int i = 1; i < x; i++) {
            if(x % i != 0) continue;
            for(int j = 2; j <= k && i * j <= x; j++) {
                dp[i*j] = min(dp[i*j], dp[i] + 1);
            }
        }
        return dp[x];
    };
    int ans = findd(x) + findd(y);
    cout << (ans >= INF ? -1 : ans) << nl;
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

