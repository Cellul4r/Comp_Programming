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
const long double pie = acosl(-1.0L);
const long double pie2 = 2.0L * pie;
const double EPS = 1e-6;
void solve(){
    
    int n,e; cin>>n>>e;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        double x;
        cin>>x;
        x += 1.0 * EPS;
        if(2.0 * x < e) {
            ans++;
            continue;
        }
        double k = acos((2.0*x*x-e*e) / (2.0*x*x));
        //cout << (2.0*x*x-e*e) / (2.0*x*x) << " " << k << nl;
        ans += (ll)(2.00 * pie / k);
        //cout << (ll)(2.00 * pie / k) << nl;
    }
    cout << ans;
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

