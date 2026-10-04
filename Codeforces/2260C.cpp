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
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    ll x,y; cin>>x>>y;
    ll op = 0;
    for(int i = 29; i >= 0; i--) {
        ll xx = (x >> i) & 1;
        ll yy = (y >> i) & 1;
        if(xx != yy) continue;
        if(x == 0) break;
        ll l = 0, k = 0;
        l = ((1<<i) - 1) & x;
        k = (y & ((1<<i) - 1)) ^ ((1<<i)-1);
        if(l == 0) continue; // never go this condition!
        /*
        cout << x << " " << y << nl;
        cout << i << " " << l << " " << k << nl;
        */
        if(xx == 0 and yy == 0) {
            // y must do k + 1 operation to make bit i = 1
            if(k < l) {
                x -= k + 1;
                y += k + 1;
                op += k + 1;
            }
        } else {
            assert(xx == 1 and yy == 1);
            // x must do l + 1 operation to make bit i = 0
            // y must do k + 1 operation to make bit i = 0 
            if(l < k) {
                x -= l + 1;
                y += l + 1;
                op += l + 1;
            } 
        }
    }
    cout << (x ^ y) << " " << op << nl;
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

