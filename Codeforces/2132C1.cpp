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
    ll n;
    cin>>n;
    ll ans = 0;
    while(n > 0) {
        // 3^x water melons
        ll cur = 1ll;
        int cnt = 0;
        while(cur * 3ll <= n) {
            cur *= 3;
            cnt++;
        }
        ans += cur * 3ll + cnt * (cur / 3ll);
        n -= cur;
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

