#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
void solve() {
    int n;
    cin>>n;
    ll lcm_ = 1;
    cout << n << '\n';
    for(ll i = 1; i <= n - 1; i++) {
        cout << i << " ";
        lcm_ = lcm(lcm_, i);
    }
    cout << lcm_;
    cout << '\n';
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
