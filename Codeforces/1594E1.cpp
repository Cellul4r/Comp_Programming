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
const ll LINF = INF;

void setIO(string);

ll modPow(ll x, ll y) {
    if(y == 0) return 1ll;
    ll t = modPow(x, y / 2ll);

    if(y & 1) {
        return t * (t * x % LINF) % LINF;
    } else {
        return t * t % LINF;
    }
}
void solve(){
    
    int n;
    cin>>n;

    cout << (6ll * modPow(4ll, (1ll << n) - 2)) % LINF << nl;
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

