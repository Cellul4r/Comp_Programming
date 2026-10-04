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
    
    ll s,m; cin>>s>>m;

    vector<bool> bitflag(64);
    for(int i = 0; i < 64; i++) {
        if((1ll<<i) & m) {
            bitflag[i] = true;
        }
    }
    auto f = [&](ll k) {
        vector<ll> bit(64);
        for(int i = 0; i < 64; i++) {
            if((1ll<<i) & s) {
                bit[i] = 1;
            }
        }
        for(int i = 63; i > 0; i--) {
            if(bit[i] == 0) continue;
            if(!bitflag[i]) {
                bit[i-1] += 2ll * bit[i];
                bit[i] = 0;
            } else {
                ll x = min(k, bit[i]);
                x = bit[i] - x;
                bit[i-1] += 2ll * x;
                bit[i] -= x;
            }
        }

        for(int i = 0; i < 64; i++) {
            if(bit[i] > k) return false;
            if(bit[i] && !bitflag[i]) {
                return false;
            }
        }

        return true;
    };

    ll l = 1, r = s;
    ll target = -1;
    while(l <= r) {
        ll mid = l + (r - l) / 2ll;
        if(f(mid)) {
            target = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << target << nl;
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

