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
const int N =501;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
const int dr[] = {-1,0,1}, dc[] = {1,1,1};
int r,c,n;
int a[N][N], dp[N][N][12];
bool check(int rr, int cc) {
    if(cc == 0 || cc == c - 1 || rr == 0 || rr == r - 1) return false;
    if(a[rr][cc-1] == -1 || a[rr][cc+1] == -1 || a[rr-1][cc] == -1 || a[rr+1][cc] == -1) return false;
    return (a[rr][cc] > a[rr][cc-1] && a[rr][cc] > a[rr][cc+1] &&
            a[rr][cc] < a[rr-1][cc] && a[rr][cc] < a[rr+1][cc]);
}
int recur(int i, int j, int p) {
    if(a[i][j] == -1) return INF;
    if(check(i,j)) {
        p++;
    }
    if(j == c-1) {
        return (p == n ? a[i][j] : INF); 
    }
    if(p > n) return INF;
    if(dp[i][j][p] != -1) return dp[i][j][p];
    //cout << i << " " << j << " " << p << nl;
    int ans = INF;
    for(int k = 0; k < 3; k++) {
        int ni = i + dr[k], nj = j + dc[k];
        if(ni < 0 || ni >= r) continue;
        ans = min(ans, a[i][j] + recur(ni,nj,p));
    }
    return dp[i][j][p] = ans;
}
void solve(){
    
    cin>>r>>c>>n;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin>>a[i][j];
        }
    }

    int ans = INF;
    for(int j = 0; j < r; j++) {
        ans = min(ans, recur(j,0,0));
    }
    if(ans == INF) {
        cout << "impossible";
        return;
    }
    cout << ans;
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

