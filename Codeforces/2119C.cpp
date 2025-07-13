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
    
    ll n,l,r,k;
    cin>>n>>l>>r>>k;
    if(n & 1) {
        cout << l << nl;
        return;
    }
    if(n == 2 || l == r) {
        cout << -1 << nl;
        return;
    }
    // n is even
    // does [l,r] contains power of two
    int lg = 0;
    while((1ll << lg) <= l) {
        lg++;
    }
    //cerr << (1ll << lg);
    ll x = 1ll << lg;
    if(x <= r) {
        if(k <= n - 2) {
            cout << l << nl;
        } else {
            cout << x << nl;
        }
    } else {
        cout << -1 << nl;
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

