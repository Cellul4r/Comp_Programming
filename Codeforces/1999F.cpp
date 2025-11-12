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
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e9+7;

void setIO(string);
ll modpow(ll x, ll y) {
    if(y == 0) return 1ll;
    ll t = modpow(x, y / 2ll);
    if(y & 1) {
        return (x * t % LINF) * t % LINF;
    }
    return t * t % LINF;
}

ll fact[N];
void solve(){
    
    int n,k;
    cin>>n>>k;
    int ones = 0, zeros = 0;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        if(x == 0) zeros++;
        else ones++;
    }

    ll ans = 0;
    for(int i = 0; i <= k / 2; i++) {
        if(ones < k - i) continue;
        if(zeros < i) continue;
        //cerr << i << " " << k - i << " " << ones << nl;
        ll x = (fact[ones] * modpow(fact[ones+i-k], LINF-2) % LINF) * modpow(fact[k-i], LINF-2) % LINF;
        ll y = (fact[zeros] * modpow(fact[zeros-i], LINF-2) % LINF) * modpow(fact[i], LINF-2) % LINF;
        //cerr << modpow(fact[k-1], 1) << nl;
        ans = (ans + x * y % LINF) % LINF;
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = fact[i-1] * i % LINF;
    }
    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

