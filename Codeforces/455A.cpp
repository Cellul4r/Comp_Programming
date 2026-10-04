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
int n;
ll dp[N];
ll a[N];
void solve(){
    
    cin>>n;
    // dp[i] maximum sum point currently we have to element i
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        a[x]++;
    }
    for(int i = 1; i <= 1e5; i++) {
        // not delete this value i
        dp[i] = dp[i-1];
        dp[i] = max(dp[i], a[i] * i + (i - 2 >= 0 ? dp[i-2] : 0));
    }
    cout << dp[N-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

