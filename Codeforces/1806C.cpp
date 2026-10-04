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
    
    int n; cin>>n;
    vector<ll> a(2*n+1);
    ll ans = 0;
    ll s = 0;
    for(int i = 1; i <= 2 * n; i++) {
        cin>>a[i];
        s += llabs(a[i] - (-1));
        ans += llabs(a[i]);
    }
    
    if(n == 1) {
        ll k = (a[1] + a[2]) / 2ll;
        ans = min(ans, llabs(a[1] - k) + llabs(a[2] - k));
    }

    if(n == 2) {
        ans = min(ans, llabs(a[1] - 2ll) + llabs(a[2] - 2ll) + llabs(a[3] - 2ll) + llabs(a[4] - 2ll));
    }

    if(n % 2 == 0) {
        for(int i = 1; i <= 2 * n; i++) {
            ans = min(ans, s - llabs(a[i] - (-1)) + llabs(a[i] - n));
        }
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

