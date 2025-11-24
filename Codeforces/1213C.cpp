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

    ll n,m; cin>>n>>m;
    set<ll> now;
    ll cur = 1;
    while(true) {
        ll k = (m * cur) % 10;
        if(now.count(k)) break;
        now.insert(k);
        cur++;
    }
    ll loop = now.size();
    ll k = n / m;
    ll ans = 0;
    for(int i = 1; i <= loop; i++) {
        ll dig = (m * i) % 10;
        ll cnt = (k - i + loop) / loop;
        //cerr << dig << " " << cnt << nl;
        ans += dig * cnt;
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

