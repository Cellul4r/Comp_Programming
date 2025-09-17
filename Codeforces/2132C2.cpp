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
    
    // x = 0 -> 3 coins 3 times = 9 coins
    // x = 1 -> 10 coins
    // n = 8 -> 3 + 6
    ll n,k;
    cin>>n>>k;
    ll tmp = n;
    int op = 0;
    while(n > 0) {
        // 3^x water melons
        op++;
        ll cur = 1ll;
        int cnt = 0;
        while(cur * 3ll <= n) {
            cur *= 3;
            cnt++;
        }
        n -= cur;
    }
    if(k < op) {
        cout << -1 << nl;
        return;
    }
    // 1 wat -> 3 coins
    // 3 wat -> 10 coins (1 + 1 + 1 better = 9 coins)
    // 9 wat -> 33 coins (3 + 3 + 3 better = 30 coins, 1 * 9 = 27 coins)
    // 27 wat -> 189 coins (9 + 9 + 9 better = 99 coins, 3 * 9 = 90 coins, 1 * 27 = 81 )
    n = tmp;
    ll diff = k - op;
    ll ans = 0;
    while(n > 0) {
        ll cur = 1ll;
        int cnt = 0;
        while(cur * 3ll <= n) {
            cur *= 3;
            cnt++;
        }
        ll a = 1ll,b = 0;
        for(int i = cnt; i >= 0; i--) {
            if(i != cnt) {
                a *= 3ll;
                b++;
            }
            ll k = cur / a - 1;
            if(k > diff) continue;
            diff -= k;
            break;
        }
        
        //cout << a << " " << b << nl;
        ans += (cur / a) * ((3ll * a) + b * (a / 3ll));     
        n -= a * (cur / a);
    }
    cout << ans << nl;
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

