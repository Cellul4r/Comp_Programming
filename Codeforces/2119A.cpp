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
    
    int a,b;
    ll x,y;
    cin>>a>>b>>x>>y;
    if(a == b) {
        cout << 0 << nl;
        return;
    }
    if(a > b) {
        if((a ^ 1) == b) {
            cout << y << nl;
        } else {
            cout << -1 << nl;
        }
        return;
    }
    // addition and do xor
    ll ans = 0;
    while(a != b) {
        if(y < x && (a & 1) == 0) {
            ans += y;
            a ^= 1;
        } else {
            ans += x;
            a++;
        }
    }
    cout << ans<<nl;
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

