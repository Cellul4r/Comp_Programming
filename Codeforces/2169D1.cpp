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
        
    ll x,y,k; cin>>x>>y>>k;
    assert(x <= 1e5);
    if(k < y) {
        cout << k << nl;
        return;
    }

    auto f = [&](ll now) {
        ll cur = now;
        for(ll i = 1; i <= x; i++) {
            if(cur == 0) return 0ll;
            cur -= cur / y;
        }
        return cur;
    };

    ll check = f(1e12);
    if(check < k) {
        cout << -1 << nl;
        return;
    }
    ll l = 1, r = 1e12;
    while(l < r) {
        ll mid = l + (r - l) / 2ll;
        if(f(mid) >= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << nl;
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

