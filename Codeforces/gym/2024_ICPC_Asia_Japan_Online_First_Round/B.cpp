#include <bits/stdc++.h>
using namespace std;

int n;
void solve() {
    
    vector<int> a(n),b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    int x = 0, y = 0;
    int lead = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        x += a[i], y += b[i];
        if(x > y && lead == 2) {
            ans++;
        } else if(x < y && lead == 1) {
            ans++;
        }
        if(x > y) {
            lead = 1;
        } else if(x < y){
            lead = 2;
        }
    }
    cout << ans << '\n';
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>n) {
        if(n == 0) break;
        solve();
    }
    return 0;
}
