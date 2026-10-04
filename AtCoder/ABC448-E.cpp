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
ll INF = 10007; 
const ll LINF = 1e18+7;

void setIO(string);
ll poww(ll x, ll y) {
    if(y == 0) return 1ll;
    ll t = poww(x, y / 2ll);
    if(y & 1) {
        return (x * t % INF) * t % INF;
    }
    return t * t % INF;
}
void solve(){
    
    int k, m; cin>>k>>m;
    INF *= m;
    ll ans = 0;
    ll cur = 0;
    vector<array<ll,2>> c(k);
    for(int i = 0; i < k; i++) {
        cin>>c[i][0]>>c[i][1];
    }

    vector<ll> pow10(30);
    pow10[0] = 10;
    for(int i = 1; i < 30; i++) {
        pow10[i] = pow10[i-1] * pow10[i-1] % INF;
    }
    vector<ll> rep(30);
    rep[0] = 1;
    for(int i = 1; i < 30; i++) {
        rep[i] = (rep[i-1]*pow10[i-1] + rep[i-1]) % INF;
    }
    for(int i = k - 1; i >= 0; i--) {
        ll a = c[i][0], b = c[i][1];
        ll now = a * poww(10ll, cur) % INF;
        // calculate sum 10^0 + 10^1 + .... + 10^(l-1) with binary lifting
        ll x = 0;
        for(int j = 29; j >= 0; j--) {
            if(b & (1ll << j)) {
                x = (x * pow10[j] + rep[j]) % INF;
            }
        }
        ans = (ans + now * x % INF) % INF;
        cur += b;
    }
    cout << ans / m;
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

