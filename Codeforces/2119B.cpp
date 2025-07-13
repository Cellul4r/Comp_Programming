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
ll dist(ll x, ll y, ll p, ll q) {
    return 1ll * (x - p) * (x - p) + 1ll * (y - q) * (y - q);
}
void solve(){
    
    int n;
    ll px,py,qx,qy;
    cin>>n>>px>>py>>qx>>qy;
    vector<ll> a(n+1);
    ll mx = 0,now = 0;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        now += a[i];
        mx = max(mx, a[i]);
    }
    
    ll k = max(0ll, 2ll * mx - now);
    ll d = dist(px,py,qx,qy);
    if(k * k <= d && d <= now * now) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }
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

