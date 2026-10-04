/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    ll n; cin>>n;
    ll l = 1, r = n;
    auto f = [&](ll k) {
        ll cur = n;
        ll tot = 0;
        while(cur >= k) {
            cur -= k;
            tot += k;
            cur = cur - (cur / 10ll);
        }
        tot += cur;
        return tot >= (n + 1ll) / 2ll;
    };

    while(l < r) {
        ll m = l + (r - l) / 2ll;
        if(f(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << nl;
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

