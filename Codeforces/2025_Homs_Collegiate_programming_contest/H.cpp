#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
void solve() {
    ll l,r;
    cin>>l>>r;
    if(l == r) {
        cout << l << '\n';
        return;
    }
    ll ans = r + gcd(l,r) + (r - l + 1ll) - 2ll;
    cout << ans << '\n';
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
