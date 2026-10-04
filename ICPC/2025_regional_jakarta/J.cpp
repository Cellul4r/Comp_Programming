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

ll f(ll k) {
    while(k > 0 && (k & 1) == 0) {
        k >>= 1;
    }
    return k;
}
void solve(){
    
    ll n,a,b;
    cin>>n>>a>>b;
    if(a != b) {
        cout << "NO";
        return;
    }

    n = f(n);
    bool ok = false;
    ll m = n & (n << 1);
    m = m | (m << 1);
    if(n == f(m)) {
        ok = true;
    }
    m = n | (n << 1);
    m = m & (m << 1);
    if(n == f(m)) {
        ok = true;
    }
    cout << (ok ? "YES" : "NO");
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

