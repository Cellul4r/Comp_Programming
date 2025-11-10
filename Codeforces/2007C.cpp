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
    
    ll n,a,b;
    cin>>n>>a>>b;
    vector<ll> c(n);
    ll d = gcd(a,b);
    for(auto &x : c) {
        cin>>x;
        // decrease all value by k*a then value x < a
        x %= d;
    }

    sort(all(c));
    ll ans = c[n-1] - c[0];
    for(int i = 1; i < n; i++) {
        ans = min(ans, c[i-1] + d - c[i]);
    }
    cout << ans << nl;
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

