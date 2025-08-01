#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
void solve() {
    
    int n,m;
    cin>>n>>m;
    vector<int> a(n), one(30), zero(30);
    vector<bool> need(30);
    int mx = 0;
    bool equal = true;
    for(auto &x : a) {
        cin>>x;
        if(x != a[0]) {
            equal = false;
        }
        for(int i = 0; i < 30; i++) {
            if((1 << i) & x) {
                one[i]++;
            } else {
                zero[i]++;
            }
        }
    }
    
    for(int i = 0; i < 30; i++) {
        if(one[i] > 0 && zero[i] > 0) {
            need[i] = true;
        }
    }

    int val = 0;
    for(int i = 0; i < 30; i++) {
        if(need[i]) {
            val |= (1 << i);
        }
    }
    vector<int> dp(n+1);
    for(int i = 0; i < n; i++) {
        if((a[i] & val) == val) {
            dp[i+1] = dp[i];
        } else {
            dp[i+1] = dp[max(0,i-m+1)] + 1;
        }
    }
    int q;
    cin>>q;
    while(q--) {
        int x;
        cin>>x;
        int k = (x & val);
        if(equal) {
            cout << 0 << '\n';
            continue;
        }
        if(k != val) {
            cout << -1 << '\n';
            continue;
        }
        bool all = false;
        for(int i = 0; i < 30; i++) {
            if(zero[i] == n && ((1 << i) & x)) {
                all = true;
            }
        }
        cout << (all ? (n + m - 1) / m : dp[n]);
        cout << '\n';
    }
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
