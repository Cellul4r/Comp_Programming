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
    
    // 8 10 10
    // 1, 21, 41, 61
    // how many of k group of g days we need to create good quality pavements? (n+1)/2
    ll n,b,g; cin>>n>>g>>b;
    ll half = (n+1) / 2ll;
    /* k * g >= half
     *  k >= half / g
     *  k = (half + g - 1) / g
     *  a1 = 1, d = g + b, ak=?
     *  ak = a1 + (k - 1) * d
    */ 
    ll k = (half + g - 1) / g;
    ll now = 1 + (k - 1) * (b + g);
    ll left = half - (k - 1) * g; // number of good days in the last group that """have used."""
    ll ans = now + left - 1;
    
    //cerr << ans << " " << k << " " << now << " " << left << nl;
    if(ans < n) {
        ll cur = ans;
        ll need = min(n - cur, left);
        cur += need;
        ans += need;
        if(cur < n) {
            // still need more
            // cur + b + g + b + g + ... >= n
            need = (n - cur) / (b + g);
            ans += need * (b + g);
            need = (n - cur) % (b + g);
            ans += need;
        }
    }
    // n = 11 
    // ggg bbb ggg bb
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

