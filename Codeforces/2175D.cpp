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
const int N =361;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n,x;
int nn;
int a[N];
vector<array<int,2>> save;
int dp[N][N][N];
int recur(int i, int j, int k) {
    if(i == n) {
        return 0;
    }
    if(dp[i][j][k] != -1) return dp[i][j][k];
    //cerr << i << " " << j << " " << k << nl;
    int ans = 0;
    ans = max(ans, k * ((i + 1 < n ? save[i+1][1] : nn + 1) - save[i][1]) + recur(i+1, j, k));
    for(int l = k + 1; l <= save[i][0] && j + l <= x; l++) {
        ans = max(ans, l * ((i + 1 < n ? save[i+1][1] : nn + 1) - save[i][1]) + recur(i+1, j + l, l)); 
    }
    return dp[i][j][k] = ans;
}
void solve(){
    
    cin>>n>>x;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    int mx = -1;
    save.clear();
    for(int i = 1; i <= n; i++) {
        if(a[i] > mx) {
            mx = a[i];
            save.push_back({mx,i});
            //cerr << mx << " " << i << nl;
        }
    }
    nn = n;
    n = save.size();
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= x; j++) {
            for(int k = 0; k <= x; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    int ans = recur(0,0,0);
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

