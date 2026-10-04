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
    // dp[i] the maximum consecutive number such that the last number divide a[i] and < a[i]
    vector<int> a(n+1), dp(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        dp[i] = 1;
    }
    
    auto f = [&](int i, int j) {
        return (a[i] < a[j]);   
    };
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j * j <= i; j++) {
            if(i % j != 0 || i == j) continue;
            if(f(j, i)) {
                dp[i] = max(dp[i], 1 + dp[j]);
            }
            if(i / j != j && f(i/j,i)) {
                dp[i] = max(dp[i], 1 + dp[i/j]);
            }
        }
    }
    cout << *max_element(all(dp)) << nl;
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

