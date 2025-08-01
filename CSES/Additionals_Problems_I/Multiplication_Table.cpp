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
    cin>>n;

    ll middle = (1ll * n * n + 1) / 2ll;
    //cerr << middle << nl;
    auto f = [&](ll x) {
        ll seq = 0;
        for(ll i = 1; i <= n; i++) {
            ll j = min(x/i,1ll*n);
            seq += j;
        }

        return seq >= middle;
    };
    ll l = 1, r = 1ll * n * n;
    while(l < r) {
        ll mid = l + (r - l) / 2ll;
        if(f(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l;
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

