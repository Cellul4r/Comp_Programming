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
    
    int n,k;
    ll x;
    cin>>n>>k>>x;
    vector<ll> a(n);
    for(auto &x : a) cin>>x;
    for(int i = 1; i < n; i++) a[i] += a[i-1];

    ll ans = -1;
    ll l = 0, r = 1ll * n * k - 1; 
    while(l <= r) {
        ll mid = l + (r - l) / 2;
        ll idx = mid % n;
        ll now = k - mid / n - 1;
        ll val = (idx - 1 < 0 ? 0 : a[idx-1]);
        ll sum = now * a[n-1] + (a[n-1] - val); 
        //cerr << mid << " " << idx << " " << now << " " << sum << nl;
        if(sum >= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans + 1 << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

