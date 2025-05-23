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

ll pow2[31], pow5[14];
ll digit(ll x) {
    ll cnt = 0;
    while(x % 10 == 0) {
        cnt++;
        x /= 10;
    }
    return cnt;
}


void solve(){
    
    ll n,m;
    cin>>n>>m;

    // 2^x + 5^y = k such that k <= m
    ll ans = n * m;
    for(int i = 0; i <= 30; i++) {
        for(int j = 0; j <= 13; j++) {
            ll now = pow2[i] * pow5[j];
            if(now > m) break;

            if(digit(n * now) < digit(ans)) continue;
            ll l = 1, r = m, k = 0;
            while(l <= r) {
                ll mid = l + (r - l) / 2ll;
                if(now * mid <= m) {
                    k = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            if(digit(n * now * k) == digit(ans)) {
                ans = max(ans, n * now * k);
            } else {
                ans = n * now * k;
            }
        }
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    pow2[0] = pow5[0] = 1;
    for(int i = 1; i < 31; i++) {
        pow2[i] = pow2[i - 1] * 2ll;
    }
    for(int i = 1; i < 14; i++) {
        pow5[i] = pow5[i - 1] * 5ll;
    }
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

