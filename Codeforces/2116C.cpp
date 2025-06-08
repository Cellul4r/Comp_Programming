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

void setIO(string);
int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
void solve(){
    
    int n;
    cin>>n;
    int gcd_ = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        gcd_ = gcd(a[i],gcd_);
    }
    sort(all(a));
    // convert all to gcd
    // but how?
    // MINIMUM MOVE TO ONE NUMBER CONVERT TO THAT GCD
    int ans = INF;
    // dp[i] minimum move to let a[i] be the gcd_
    vector<int> dp(5001,INF);
    dp[gcd_] = 0;
    for(int i = gcd_+1; i <= 5000; i++) {
        for(int j = 0; j < n; j++) {
            int v = gcd(i,a[j]);
            if(dp[v] == INF) continue;
            dp[i] = min(dp[i], 1 + dp[v]);
        }
    }
    int idx = -1; 
    for(int i = 0; i < n; i++) {
        if(dp[a[i]] < ans) {
            idx = i;
            ans = dp[a[i]];
        }
    }
    //cerr << ans << nl;
    for(int i = 0; i < n; i++) {
        if(a[i] == gcd_ || i == idx) continue;
        ans++;
    }
    cout << ans << nl;
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

