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
    
    ll l,r,d,u;
    cin>>l>>r>>d>>u;
    ll ans = 0;

    auto f = [&](ll x, ll y) {
        if(x > y) return 0ll;
        x += 2e6;
        y += 2e6;
        return (y / 2ll) - ((x - 1ll) / 2ll);
    };
    for(int x = l; x <= r; x++) {
        ll k = abs(x);
        // top black
        // all y such that k < y < u
        ans += f(max(d,k+1),u);
        // all y such that d < y < -k
        ans += f(d,min(u,-k-1));
        if(max(-k,d) <= min(k,u) && k % 2 == 0) {
            ans += min(k,u) - max(-k,d) + 1;
        }
    }
    cout << ans;
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

