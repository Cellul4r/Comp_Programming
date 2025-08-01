#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {

    int n;
    ll x;
    cin>>n>>x;
    vector<ll> a(n);
    for(auto &x : a) cin>>x;
    vector<pair<ll,int>> div;
    ll cur = x;
    for(ll i = 2; i*i <= x; i++) {
        if(cur % i == 0) {
            int cnt = 0;
            while(cur % i == 0) {
                cur /= i;
                cnt++;
            }
            div.push_back(make_pair(i,cnt));
        }
    }
    if(cur > 1) {
        div.push_back(make_pair(cur,1));
    }
    for(auto &y : a) {
        // find least divisor that divisible now
        ll ans = -1;
        for(auto &[x,ex] : div) {
            ll now = y;
            ll ey = 0;
            while(now % x == 0) {
                now /= x;
                ey++;
            }

            if(ey < ex) {
                ll ans2 = pow(x, ey+1);
                if(ans == -1 || ans2 < ans) {
                    ans = ans2;
                }
            }
        }
        cout << ans << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
