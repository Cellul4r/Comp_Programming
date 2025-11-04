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
void test(ll l, ll r) {
    for(ll k = l; k <= r; k++) {
        if(k % (ll)sqrtl(k) == 0) {
            cerr << k << nl;
        }
    }
}

ll answer(ll k) {
    if(k == 0) return 0ll;
    if(k == 1) return 1ll;
    ll x = sqrtl(k) + 1ll; 
    ll ans = (x - 1) + (x - 2) * 2ll;
    ll l = x, r = k / (x - 1); 
    //cerr << ans << nl;
    if(l == r) {
        ans++;
    } else if(l < r) {
        ans += 2;
    }
    return ans;
}
void solve(){
    
    ll l,r; cin>>l>>r;
    //test(l,r);
    cout << answer(r) - answer(l-1) << nl;
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

