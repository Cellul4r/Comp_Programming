#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    int ans = 1;
    vector<int> now(n);
    now[0] = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i-1]) {
            now[i] = now[i-1] + 1;
        } else {
            now[i] = 1;
        }
        ans += now[i];
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
