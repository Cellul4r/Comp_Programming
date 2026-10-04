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
bool palin(ll x) {
    ll now = 0;
    ll tmp = x;
    while(tmp) {
        now = now * 10ll + (tmp % 10ll);
        tmp /= 10ll;
    }
    return now == x;
}
void solve(){
    
    // 1 -> 1 + 0
    // 10 -> -1
    // 13 -> 1 + 12
    // 20 -> 8 + 12
    // 23 -> 11 + 12
    // 24 -> 0 + 24
    // 25 -> 1 + 24
    // 
    // 100 -> 88 + 12
    // 101 
    // 102 -> 
    // 106 -> 22 + 84
    // 107 -> 23 + 84
    // 1000 -> 88 + 912
    // 10000 -> 88 + 9912
    // 111 -> 99 + 12
    ll n; cin>>n;
    if(n <= 9ll) {
        cout << n << " " << 0 << nl;
        return;
    }
    if(n == 10ll) {
        cout << -1 << nl;
        return;
    }
    if(n % 12ll == 0ll) {
        cout << 0 << " " << n << nl;
        return;
    }
    if(palin(n)) {
        cout << n << " " << 0 << nl;
        return;
    }

    // rem = 10, rem = 11
    if(n % 12ll == 10ll) {
        cout << 22 << " " << n - 22 << nl;
        return;
    }
    ll k = n / 12ll * 12ll;
    cout << n - k << " " << k << nl;
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

