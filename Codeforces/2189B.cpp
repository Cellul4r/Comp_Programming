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
    
    int n;
    ll x; cin>>n>>x;
    vector<array<ll,3>> a;
    ll cur = 0;
    ll ans = -1;
    for(int i = 0; i < n; i++) {
        ll y,z,w; cin>>y>>z>>w;
        a.push_back({y,z,w});
        cur += (z-1) * y; 

        ll k = y * z - w;
        if(k > 0) {
            ans = max(ans, k);
        }
    }

    if(cur >= x) {
        cout << 0 << nl;
        return;
    }

    if(ans == -1) {
        cout << -1 << nl;
        return;
    }

    ans = (x - cur + ans - 1) / ans;
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

