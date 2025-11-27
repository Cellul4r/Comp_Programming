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
    
    ll r;
    cin>>r;
    /*
     * r = x*x + 2xy + x + 1
     * r = x * (x + 1) + 2xy + 1
     * 1. r is always odd number
     * r - 1 - x(x+1) = 2xy
     * (r - 1 - x(x+1)) / 2x = y
     * r > 1 + x(x+1)
     */
    for(ll x = 1; x <= 1e6; x++) {
        if(r <= 1 + x * (x + 1)) break;
        ll k = r - 1 - x * (x + 1);
        if(k % (2ll * x) == 0) {
            cout << x << " " << k / (2ll * x);
            return;
        }
    }

    cout << "NO";
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

