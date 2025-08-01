#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n), pre(n+1), suff(n+2);
    for(auto &x : a) {
        cin>>x;
    }
    int ans = 0;
    pre[0] = (1 << 30) - 1;
    suff[n+1] = (1 << 30) - 1;
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] & a[i-1];
    }
    for(int i = n; i >= 1; i--) {
        suff[i] = suff[i+1] & a[i-1];
    }
    for(int i = 0; i < n; i++) {
        ans = max(ans, abs(a[i] - (pre[i] & suff[i+2])));
    }
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
