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
const int N =4e6+1;
const ll INF = 998244353;
const ll LINF = 1e18+7;

ll a,b,c,d;
ll sum;
ll fact[N];

ll inv(ll x, ll y) {
    if(y == 0) return 1;
    ll t = inv(x, y / 2);
    if(y & 1) {
        return ((t * t) % INF) * x % INF;
    } else {
        return (t * t) % INF;
    }
}
void solve(){
    
    cin>>a>>b>>c>>d;
    sum = a + b + c + d;

    // for each position from left to right try to put 1 grape on that position
    // and check is it a valid position?
    ll ans = 0;
    // grape
    ans += ((fact[d + c - 1] * inv(fact[d-1], INF-2) % INF) * inv(fact[c], INF-2) * fact[a+b] % INF) * inv(fact[a], INF-2) * inv(fact[b], INF-2); 
    ans %= INF;
    cerr << ans << nl;
    for(ll i = a; i < sum; i++) {
        ll k = min(b,max(sum - i - 1 - d, 0ll)); 
        ll now = fact[k];
        cerr << i << " " << k << nl;
        if(a + b - k > i) continue;
        if(sum - i - 1 < d + c - 1) continue;
        now = (now * (fact[a + b - k] * inv(fact[a], INF-2) % INF) % INF) * inv(fact[b - k], INF-2) % INF;
        now %= INF;
        now = now * (fact[d + c - 1] * inv(fact[d], INF-2) % INF) * inv(fact[c - 1], INF-2) % INF;
        now %= INF;
        ans += now;
        cerr << now << nl;
        ans %= INF;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = fact[i-1] * i;
        fact[i] %= INF;
    }
    //cin>>t;
    while(t--)solve();

    return 0;
}

