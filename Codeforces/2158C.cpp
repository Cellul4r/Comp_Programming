/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n,k;
    cin>>n>>k;
    vector<vector<ll>> dp(n+1,vector<ll>(2));
    vector<ll> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin>>b[i];
    }

    for(int i = 1; i <= n; i++) {
        dp[i][0] = max(a[i], dp[i-1][0] + a[i]);
        dp[i][1] = max(a[i], dp[i-1][1] + a[i]);
        dp[i][1] = max({dp[i][1],a[i] + b[i], dp[i-1][0] + a[i] + b[i]});
    }

    ll ans1 = -LINF, ans2 = -LINF;
    for(int i = 1; i <= n; i++) {
        ans1 = max(ans1, dp[i][0]);
        ans2 = max(ans2, dp[i][1]);
    }
    if(k % 2 == 0) {
        cout << ans1;
    } else {
        cout << ans2;
    }
    cout << nl;
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

