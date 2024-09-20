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
using pii = pair<int,int>;
using piL = pair<int,long>;
using pip = pair<int,pair<int,int>>;
const int INF = 1e9;
const int N = 2e5+3;
const ll mod = 1e12+7;

ll a[N];
ll dp[N][2];
ll recur(int i,int n,bool prev) {

    ll k;
    if(prev) {
        k = -1LL;
    } else {
        k = 1LL;
    }
    if(i == n-1) return a[i] * k;
    if(dp[i][prev] != -INF) return dp[i][prev];
    ll sum = -INF;
    sum = max(sum,max(recur(i+1,n,false) + a[i] * k, recur(i+1,n,true) + -1LL * a[i] * k));
    cout << i << " " << prev << " SUM: " << sum << endl;
    return dp[i][prev] = sum;
}
void solve() {
 
    int n;
    cin>>n;
    for(int i=0;i<n;++i) {
        cin>>a[i];
        for(int j=0;j<2;++j) {
            dp[i][j] = -INF;
        }
    }
    dp[n-1][0] = a[n-1];
    dp[n-1][1] = a[n-1]*-1;
    for(int i=n-2;i>=0;--i) {
        dp[i][0] = max(a[i] + dp[i+1][0],a[i]*-1 + dp[i+1][1]);
        dp[i][1] = max(a[i]*-1 + dp[i+1][0],a[i] + dp[i+1][1]);
    }
    cout << dp[0][0] << endl;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin>>t;
    //sf("%d",&t); 
    while(t--) {
        solve();
    }
    return 0;
}
/*
 */
