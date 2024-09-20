#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define L long
#define sLL signed long long
#define uLL unsigned long long
#define f first 
#define s second
#define pf printf
#define sf scanf
#define A(a) (a).begin(),(a).end()
using pii = pair<int,int>;
using piL = pair<int,long>;
using pip = pair<int,pair<int,int>>;
const int INF = 1e9;
const int N = 2e5+3;
const int mod = 1e9+7;

ll dp[2][N];
ll recur(ll i, int up, ll n, ll a, ll b, string& s) {

    if(i == n-1) {
        if(up) return (3*b + 2*a);
        return (2*b + a);
    }

    if(~dp[up][i]) return dp[up][i];
    ll ans = LLONG_MAX;
    if(s[i] == '0') {
        if(up) {
            if(s[i+1] != '1') ans = min(ans,2*b + 2*a + recur(i+1, false, n, a, b, s));
            ans = min(ans,2*b + a + recur(i+1, true, n, a, b, s));
        } else{
            if(s[i+1] != '1') ans = min(ans,b + a + recur(i+1, false, n, a, b, s));
            ans = min(ans,b + 2*a + recur(i+1, true, n, a, b, s));
        }
    } else {
        ans = min(ans, 2*b + a + recur(i+1, true, n, a, b, s));
    }
    //cout << i << " UP? : " << up << " ANS: " << ans << endl;
    return dp[up][i] = ans;
}
void solve() {

    memset(dp,-1,sizeof(dp));
    ll n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    auto ans = recur(0,false,n,a,b,s);
    cout << ans << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
/*
 */
