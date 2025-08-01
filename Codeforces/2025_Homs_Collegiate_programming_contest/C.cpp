#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {

    int n;
    ll m;
    cin>>n>>m;
    vector<ll> a(n), b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    auto f = [&](ll y) {
        ll now = m;
        for(int i = 0; i < n; i++) {
            ll x = (a[i] * b[i] - y + b[i] - 1) / b[i];
            x = max(0ll, x);
            now -= x;
        }
        return now >= 0;
    };
    ll l = 0, r = 1e18;
    while(l < r) {
        ll mid = l + (r - l) / 2ll;
        if(f(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
