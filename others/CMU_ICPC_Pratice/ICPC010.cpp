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
ll maxSum(vector<ll>& a, int n) {
    
    vector<ll> dp1(n), dp2(n);
    // dp1 maximum sum end at i
    // dp2 minimum sum start at i
    dp1[0] = a[0];
    for(int i = 1; i < n; i++) {
        dp1[i] = max(dp1[i-1] + a[i], a[i]);
    }

    dp2[n-1] = a[n-1];
    for(int i = n - 2; i >= 0; i--) {
        dp2[i] = min(dp2[i+1] + a[i], a[i]);
    }

    ll mx = 0;
    for(int i = 0; i < n - 1; i++) {
        mx = max(mx, dp1[i] - dp2[i+1]);
    }
    return mx;
}
void solve(){
    
    int n;
    cin>>n;
    vector<ll> a(n);
    for(auto &x : a) cin>>x;
    ll ans1 = maxSum(a,n);
    reverse(all(a));
    ll ans2 = maxSum(a,n);
    cout << max(ans1,ans2);
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

