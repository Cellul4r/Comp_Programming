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
    
    int n; cin>>n;
    vector<ll> a(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        sum += a[i];
    }

    ll k = (sum + 1ll) / 2ll;
    ll ans = k;
    sort(all(a));
    for(auto &x : a) {
        ll y = min(k, x);
        x -= y;
        k -= y;
    }
    k = sum / 2ll;
    for(auto &x : a) {
        if(x == 0) continue;
        ll y = min(k, x);
        x -= y;
        k -= y;
        ans++;
        if(x > 0) {
            ans += x;
            x = 0;
        }
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

