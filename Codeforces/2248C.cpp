/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =2e5+5;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
ll dp[2*N][3];
int n; 
vector<int> a[N];
vector<int> save;
ll recur(int i, int sz) {
    if(i == 2*n+1) return 0ll;
    // 1 size
    if(dp[i][sz] != -1) return dp[i][sz];
    if(sz == 1) {
        return dp[i][1] = 1ll + max(recur(i+1, 1), recur(i+1, 2));
    }
    //cout << "HI";
    int x = save[i];
    int nxt = a[x][1];
    //cout << i << " " << nxt << nl;
    if(i == nxt) {
        // can not be 2 size
        return dp[i][1] = 1ll + max(recur(i+1, 1), recur(i+1, 2));
    }
    return dp[i][2] = (nxt - i + 1) * (nxt - i + 1) + max(recur(nxt+1, 1), recur(nxt+1, 2));
}
void solve(){
    
    cin>>n;
    save.clear();
    save.push_back(0);

    for(int i = 1; i <= 2*n; i++) {
        dp[i][1] = dp[i][2] = 0;
    }

    for(int i = 1; i <= n; i++) {
        a[i].clear();
    }
    for(int i = 1; i <= 2 * n; i++) {
        int x; cin>>x; 
        a[x].push_back(i);
        save.push_back(x);
    }

    dp[2*n+1][1] = dp[2*n+1][2] = 0;
    for(int i = 2*n; i >= 1; i--) {
        // size 1
        dp[i][1] = 1ll + max(dp[i+1][1], dp[i+1][2]);
        // size 2
        int x = save[i];
        int prv = a[x][0]; 
        if(prv == i) {
            //dp[i][1] = 1ll + max(dp[i+1][1], dp[i+1][2]);
            //dp[i][2] = max(dp[i+1][1], dp[i+1][2]);
        } else {
            dp[prv][2] = 1ll * (i - prv + 1) * (i - prv + 1) + max(dp[i+1][1], dp[i+1][2]);
        }
    }
    ll ans = max(dp[1][1], dp[1][2]);
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

