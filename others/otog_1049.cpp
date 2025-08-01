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
const int k = 4;

int board[N][k];
int n;
ll dp[N][k][k];
ll recur(int l, int prevL, int r, int prevR) {
    // no ways that l = r
    if(l >= r) {
        return 0;
    }
    if(~dp[l][prevL][prevR]) return dp[l][prevL][prevR];
    ll ans = 0;
    for(int i = 0; i < k; i++) {
        if(i == prevL) continue; 
        for(int j = 0; j < k; j++) {
            if(j == prevR || i == j) continue;
            ans = max(ans, board[l][i] + board[r][j] + recur(l + 1, i, r - 1, j));
        }
    }
    return dp[l][prevL][prevR] = ans;
}
void solve(){
    
    memset(dp, -1, sizeof dp);
    cin>>n;
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < n; j++) {
            cin>>board[j][i];
        }
    }

    ll ans;
    ans = recur(0,k,n-1,k);
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

