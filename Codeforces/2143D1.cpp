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
const int N =301;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void add(int &a, int b) {
    a += b;
    if(a >= INF) a-= INF;
}
int dp[N+1][N+1][N+1];
void solve(){
    
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin>>a[i];


    vector<vector<int>> dp(n+1, vector<int>(n+1));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        vector<vector<int>> ndp(n+1, vector<int>(n+1));
        for(int j = 0; j <= n; j++) {
            for(int k = 0; k <= j; k++) {
                add(ndp[j][k], dp[j][k]);
                if(a[i] >= j) {
                    add(ndp[a[i]][k], dp[j][k]);
                } else if(a[i] >= k) {
                    add(ndp[j][a[i]], dp[j][k]);
                }
            }
        }
        swap(dp, ndp);
    }

    int ans = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= i; j++) {
            add(ans, dp[i][j]);
        }
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

