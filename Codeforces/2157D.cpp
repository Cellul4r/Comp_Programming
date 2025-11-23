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
void solve(){
    
    int n;
    ll l, r; 
    cin >> n >> l >> r;

    vector<ll> a(n); 
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(all(a));

    vector<ll> P(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        P[i + 1] = P[i] + a[i];
    }

    ll ans = -LINF;

    for (int k = -n; k <= n; ++k) {
        int m = (n + k) / 2;
        int nn = (n - k) / 2;

        if (m >= 0 && m <= n && nn >= 0 && nn <= n) {
            ll s_m = P[n] - P[n - m];
            ll s_n = P[nn];
            ll sigma = s_m - s_n;

            ll g;
            if (k >= 0) {
                g = sigma - (ll)k * r;
            } else {
                g = sigma - (ll)k * l;
            }

            ans = max(ans, g);
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

