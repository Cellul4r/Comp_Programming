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
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    ll ans = 0;
    vector<int> par(n+1), dp(n+1);
    for(int i = 1; i <= n; i++) {
        par[i] = i;
        dp[i] = 1;
    }
    if(a[1] > a[2]) {
        dp[2]++;
        par[2] = 1;
    }
    for(int i = 3; i <= n; i++) {
        if(a[i] < a[i-2] && a[i] < a[i-1]) {
            if(dp[i-1] >= dp[i-2]) {
                par[i] = i - 1;
                dp[i] = 1 + dp[i-1];
            } else {
                par[i] = i - 2;
                dp[i] = 1 + dp[i-2];
            }
        } else if(a[i] < a[i-2]) {
            par[i] = i - 2; 
            dp[i] = 1 + dp[i-2];
        } else {
            assert(a[i] < a[i-1]);
            par[i] = i - 1;
            dp[i] = 1 + dp[i-1];
        }
    }
    vector<ll> save(n+1, 1);
    for(int i = n; i >= 1; i--) {
        if(par[i] != i) {
            save[par[i]] += save[i]; 
        }
    }
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += dp[i];
    }
    ans = sum;
    for(int i = 1; i < n; i++) {
        sum -= save[i];
        ans += sum;
    }
    cout << ans << nl;
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

