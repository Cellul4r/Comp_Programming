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
ll a[N], b[N];
void solve(){

    int n; cin>>n;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin>>b[i];
    }
    ll x = 0, y = 0;
    for(int i = 1; i <= n; i++) {
        ll mx = max(x,y);
        ll mn = min(x,y);
        ll xx = mx - a[i];
        ll yy = b[i] - mn;
        ll zz = b[i] - mx;
        ll kk = mn - a[i];
        x = max({xx,yy,zz,kk});
        y = min({xx,yy,zz,kk});
    }
    cout << max(x,y) << nl;
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

