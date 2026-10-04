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
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    return a * b / gcd(a,b);
}
void solve(){
    
    ll a,b,c,m;
    cin>>a>>b>>c>>m;

    auto f = [&](ll start, ll d) {
        if(m < start) return 0ll;
        return (m - start + d) / d;
    };

    ll A = f(a, a);
    ll B = f(b, b);
    ll C = f(c, c);
    ll ab = f(lcm(a,b), lcm(a,b));
    ll ac = f(lcm(a,c), lcm(a,c));
    ll bc = f(lcm(b,c), lcm(b,c));
    ll abc = f(lcm(lcm(a,b),c), lcm(lcm(a,b),c));
    cerr << abc << nl;
    ab -= abc;
    ac -= abc;
    bc -= abc;
    A = A - ab - ac - abc;
    B = B - ab - bc - abc;
    C = C - ac - bc - abc;
    //cerr << A << " " << B << " " << C << " " << ab << " " << ac << " " << bc << " " << abc << nl;
    cout << 6ll * A + 3ll * (ab + ac) + 2ll * abc << " ";
    cout << 6ll * B + 3ll * (ab + bc) + 2ll * abc << " ";
    cout << 6ll * C + 3ll * (ac + bc) + 2ll * abc << " ";
    cout << nl;
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

