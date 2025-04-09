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

ll ceil(ll a, ll b) {
    return (a + b - 1ll) / b;
}

bool check(ll n, ll m, ll k, ll now) {

    ll total = 0;
    total += n * (m - m / (now + 1));
    //cerr << total << nl;
    return (total >= k);
}
void solve(){
    
    ll n,m,k;
    cin>>n>>m>>k;
    ll ans = 1;
    ll l = 1, r = m;
    while(l <= r) {
        ll mid = l + (r - l) / 2ll;
        //cerr << mid << nl;
        if(check(n,m,k,mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << nl;
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

