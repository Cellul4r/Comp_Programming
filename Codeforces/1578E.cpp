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
const int N =51;
const int P = 1e4+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);

void solve(){

    ll h,p;
    cin>>h>>p;

    ll now = (1ll << h) - 1;
    ll ready = 1, ans = 0;
    while(ready < now) {
        ans++;
        now -= min(ready, p);
        ready *= 2ll;
    }
    ans += (now + p - 1) / p;
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

