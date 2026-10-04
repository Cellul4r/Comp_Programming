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
const int N =5e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int a[N];
int dp[N];
int dfs(int u) {
    if(u == a[u]) {
        dp[u] = u;
        return dp[u];
    }
    if(dp[u] != 0) {
        return dp[u];
    }
    return dp[u] = dfs(a[u]);
}
void solve(){
    
    int n; cin>>n;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    for(int i = 1; i <= n; i++) {
        dfs(i);
    }

    for(int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
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

