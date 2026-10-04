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
void solve(){
    
    // suppose S0 = 0 no people that get a gift
    // where base case is min ans for each i is S0 = 0
    // S1 = ? a1 get a gift -> S1 = 2*d*a1 - a2 - a5 this is independent from other views perspective
    int n,d; cin>>n>>d;
    vector<ll> a(3*n+1), p(3*n+1);
    for(int i = 1; i <= n; i++) {
        ll x; cin>>x;
        a[i] = a[i+n] = a[i+2*n] = x;
    }
    for(int i = 1; i <= 3 * n; i++) {
        p[i] = a[i] + p[i-1];
    }

    ll ans = 0;
    for(int i = n+1; i <= 2*n; i++) {
        ll x = 2ll * d * a[i] - (p[i+d] - p[i]) - (p[i-1] - p[i-d-1]);
        ans += max(0ll, x);
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

