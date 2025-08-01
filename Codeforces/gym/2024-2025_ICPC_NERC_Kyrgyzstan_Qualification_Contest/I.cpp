#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
typedef long long ll;
int n;
ll a[N];
ll dp[N][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    dp[0][0] = a[0];
    dp[0][1] = 2 * a[0];
    for(int i = 1; i < n; i++) {
        dp[i][0] = a[i] + max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = 2 * a[i] + dp[i-1][0]; 
    }
    vector<char> ans(n,'O');
    int state = 0;
    if(dp[n-1][1] > dp[n-1][0]) {
        ans[n-1] = 'M';
        state = 1;
    }
    for(int i = n - 2; i >= 0; i--) {
        if(state == 1) {
            state = 0;
        } else if(dp[i][1] > dp[i][0]) {
            ans[i] = 'M';
            state = 1;
        }
    }
    ll res = max(dp[n-1][0], dp[n-1][1]);
    cout << res << '\n';
    for(auto &x : ans) {
        cout << x;
    }
    return 0;
}
