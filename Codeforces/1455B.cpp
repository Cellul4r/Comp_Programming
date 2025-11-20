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

    ll x;
    cin>>x;
    // 0 + kth time
    // 1 + 2 + 3 + 4 + 5 + ... >= x
    // n * (n + 1) / 2 >= x
    ll n = 1;
    while(n * (n+1) / 2ll < x) {
        n++;
    }
    ll ans = n;
    // 1 + 2 + 3 + 4 = S
    // S - k - ? = x
    // S - x = k + ?
    ll s = n * (n+1) / 2ll;
    ll cur = s - x;
    for(int i = n; i >= 1; i--) {
        if(cur >= i + 1) cur -= i + 1;
    }
    if(cur != 0) ans++;
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

