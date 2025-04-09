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

ll ceil(ll a, ll b) {
    return (a + b - 1) / b;
}
void solve(){
    
    int n,q;
    cin>>n>>q;
    for(int i = 0; i < q; i++) {
        string op;
        cin>>op;
        if(op == "->") {
            ll x,y;
            cin>>x>>y;
            ll r = 1, c = 1, sz = (1ll << n) >> 1;
            ll now = 1;
            while(sz >= 1 && (r != x || c != y)) {
                //cerr << sz << " " << r << " " << c << " " << now << nl;
                if(r + sz <= x) {
                    r += sz;
                    if(c + sz <= y) {
                        // bottom right
                        now += sz * sz;
                        c += sz;
                    } else {
                        // bottom left
                        now += 2ll * sz * sz;
                    }
                } else {
                    if(c + sz <= y) {
                        // top right
                        now += 3ll * sz * sz;
                        c += sz;
                    } else {
                        // do nothing
                    }
                }
                //cerr << sz << " " << r << " " << c << " " << now << nl;
                sz >>= 1;
            }
            cout << now << nl;
        } else {
            ll k;
            cin>>k;
            ll now = 1, sz = (1ll << n) >> 1;
            ll r = 1, c = 1;
            while(sz >= 1) {
                ll y = (k - now) / (sz * sz);
                y %= 4;
                if(y == 1) {
                    r += sz;
                    c += sz;
                } else if(y == 2) {
                    r += sz;
                } else if(y == 3) {
                    c += sz;
                }
                //cerr << y << nl;
                now += y * sz * sz;
                sz >>= 1;
            }
            cout << r << " " << c << nl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

