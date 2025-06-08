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
const int N =5000+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
vector<int> a;
int now = 0,x,n;
int dp[N][N];
int recur(int i, int k) {
    if(i == n) return 0;
    if(dp[i][k] != -1) {
        now = max(now, dp[i][k]);
        return dp[i][k];
    }
    //cerr << i << " " << k << nl;
    int ans = 0;
    ans = max(ans,a[i]);
    ans = max(ans, a[i] + recur(i+1,k));
    if(k > 0) {
        ans = max(ans, a[i] + x);
        ans = max(ans, recur(i+1,k-1) + a[i] + x);
    }
    now = max(now, ans);
    return dp[i][k] = ans;
}
void solve(){
    
    cin>>n>>x;
    a.resize(n);
    for(auto &x : a) {
        cin>>x;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }
    for(int k = 0; k <= n; k++) {
        now = 0;
        recur(0,k);
        cout << now << " ";
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

