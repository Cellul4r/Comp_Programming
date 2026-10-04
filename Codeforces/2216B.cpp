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
    
    ll t,h,u; cin>>t>>h>>u;
    ll ans = 0;
    // T and U combined
    ll k = min(t,u);
    ans += 4ll * k;
    t -= k;
    u -= k;

    // choose between THTHTH or consecutive T and H alone
    k = min(t / 2ll, h); 
    ans += 7ll * k;
    t -= 2ll * k;
    h -= k;

    k = min(t,h);
    ans += 5ll * k;
    t -= k;
    h -= k;
    if(t != 0) {
        ans += 2ll * t + 1;
        t = 0;
    }
    ans += 3ll * (t + h + u);
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

