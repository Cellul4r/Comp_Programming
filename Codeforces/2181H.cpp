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
    
    ll w,h,d;
    ll n;
    cin>>w>>h>>d>>n;

    ll wp = gcd(n, w); // 10
    n /= wp;
    ll hp = gcd(n, h); // 4
    n /= hp;
    ll dp = gcd(n, d); // 1
    n /= dp;
    if(n != 1) {
        cout << -1;
        return;
    }
    cout << wp-1 << " " << hp-1 << " " << dp-1;
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

