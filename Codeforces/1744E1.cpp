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
    
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    // a < x <= c
    // b < y <= d
    // a * b divide x*y
    // 3,5 -> 3 -> x = 
    // 4,7 -> 2^2
    // 8,15 -> 2^3
    // 9,18 -> 3^2
    // maximum number of distinct prime number is 7
    for(ll x = a + 1; x <= c; x++) {
        // when we fixed x then how can we choose y such that a * b divide x * y and b < y <= d
        //  (x * y) / (a * b)
        //  
        ll k = a * b / gcd(a*b, x);
        ll y = d / k * k;
        if(y > b) {
            cout << x << " " << y << nl;
            return;
        }
    }
    cout << -1 << " " << -1 << nl;
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

