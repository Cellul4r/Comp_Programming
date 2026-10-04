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
const int N =5e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n,q;
int row[N], col[N];
void solve(){

    cin>>n>>q;


    auto f = [&](int x, int y) {
        return x ^ y;
    };
    ll ans;
    ll rEdge = 0, cEdge = 0;
    // edge 0...n-1
    for(int i = 0; i < q; i++) {
        string op;
        int x; cin>>op>>x;
        x--;
        if(op == "ROW") {
            if(x > 0) rEdge -= f(row[x-1], row[x]);
            if(x < n-1) rEdge -= f(row[x], row[x+1]);
            row[x] ^= 1;

            if(x > 0) rEdge += f(row[x-1], row[x]);
            if(x < n-1) rEdge += f(row[x], row[x+1]);
        } else {
            if(x > 0) cEdge -= f(col[x-1], col[x]);
            if(x < n-1) cEdge -= f(col[x], col[x+1]);
            col[x] ^= 1;

            if(x > 0) cEdge += f(col[x-1], col[x]);
            if(x < n-1) cEdge += f(col[x], col[x+1]);

        }
        ans = (1ll * n - rEdge) * (1ll * n - cEdge);
        cout << ans << nl;
    }
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

