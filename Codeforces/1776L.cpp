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
    
    int n;
    string s; cin>>n>>s;
    int q; cin>>q;
    int pos = 0, neg = 0;
    for(auto &x : s) {
        if(x == '+') pos++;
        else neg++;
    }
    for(int i = 1; i <= q; i++) {
        bool ok = false;
        ll a,b; cin>>a>>b;
        if(a == b) {
            if(pos == neg) ok = true;
        } else {
            ll x = (pos-neg)*b;
            ll y = b - a;
            if(x % y == 0 && -neg <= x / y && x / y <= pos) ok = true;
        }
        cout << (ok ? "YES" : "NO") << nl;
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

