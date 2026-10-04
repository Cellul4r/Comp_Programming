/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 998244353;

void setIO(string);
ll pow(ll x, ll y) {
    if(y == 0) return 1ll;
    ll t = pow(x, y / 2ll);
    if(y & 1) {
        return (t * t % LINF) * x % LINF;
    }
    return t * t % LINF;
}
void solve(){
    
    ll n,m,r,c; cin>>n>>m>>r>>c;
    cout << pow(2ll, -1 + r*m - m - r*c + c + c*n - n + r) << nl;
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

