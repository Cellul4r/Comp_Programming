/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =2e5+1;
const ll INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
ll pow2[N];
ll pow(ll x, ll y) {
    if(y == 0) return 1ll;
    ll t = pow(x, y / 2ll);
    if(y & 1) {
        return (x * t % INF) * t % INF;
    }
    return t * t % INF;
}
void solve(){
    
    int n; cin>>n;
    // what if array not contain -1?
    // 1 2 3
    // 1 1 2 2 3 3
    // 1 2 3
    // 2 2 2
    // count number of subsequence such that all a[i] has the same number
    // else 1 4 8 has not the same number never can make ALTERNATE SUM = 0!
    // EASY!
    // 1 1 1 1 choose 2, choose 4 -> 2^(n-1) = 2^3 = 8-1 -> 2^(n-1) - 1
    // what if array contain 1?
    map<int,ll> cnt;
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        cnt[x]++;
    }
    // complete
    auto f = [&](int x) {
        ll val = pow2[cnt[x] - 1];
        return val;
    };
    ll ans = 0;
    ll cur = 1;
    for(auto &[x,y] : cnt) {
        cur = cur * f(x) % INF;
    }
    ans += cur;
    // what if using -1 to be useful?
    // -1, (-1,-1,-1), (-1,-1,-1,-1,-1) -> tmpSum = -1
    // -1 - 1 = -2 (2-2+2)
    if(cnt[-1] > 0) {
        ll one = f(-1);
        cur = cur * pow(f(-1), INF - 2ll) % INF;
        for(auto &[x,y] : cnt) {
            if(x == -1) continue;
            if(cnt.find(x+1) == cnt.end()) continue;
            ll now = (cur) * pow(f(x+1), INF - 2ll) % INF;
            //cerr << one << " " << now << " " << f(x+1) <<  nl;
            ans = (ans + (one * now % INF) * f(x+1) % INF) % INF;
        }
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    pow2[0] = 1;
    for(int i = 1; i < N; i++) {
        pow2[i] = pow2[i-1] * 2ll % INF;
    }
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

