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
    
    int n; cin>>n;
    vector<ll> a(n);
    for(auto &x : a) cin>>x;
    ll ans = 0;
    for(int i = 1; i < n; i+= 2) {
        ll left = a[i-1];
        ll right = (i + 1 < n ? a[i+1] : 0);
        if(a[i] >= left + right) continue;
        if(i + 1 < n) {
            ll k = min(a[i+1], left + right - a[i]);
            a[i+1] -= k;
            right = a[i+1];
            ans += k;
        }
        ll k = max(0ll,min(a[i-1], left + right - a[i]));
        a[i-1] -= k;
        ans += k;
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

