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
const int N =210;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n,m;
int a[N][N];
int dp[N][N];
int par[N][N];
int ans;
vector<int> path;
vector<int> findPath(int i) {
    int j = 1;
    vector<int> cur;
    while(j <= m) {
        cur.push_back(i); 
        i = par[i][j];
        j++;
    }
    //reverse(all(cur));
    return cur;
}
void solve(){

    while(cin>>n>>m) {
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <= m; j++) {
                cin>>a[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= m; j++) {
                par[i][j] = INF;
                dp[i][j] = 0;
            }
        }

        for(int i = 0; i < n; i++) dp[i][m] = a[i][m];
        for(int j = m-1; j >=1; j--) {
            for(int i = 0; i < n; i++) {
                dp[i][j] = INF;
                vector<int> prev{(i-1+n)%n,i,(i+1)%n};
                sort(all(prev));
                for(auto &r : prev) {
                    if(dp[r][j+1] < dp[i][j]) {
                        dp[i][j] = dp[r][j+1];
                        par[i][j] = r;
                    }
                }
                dp[i][j] += a[i][j];
            }
        }
        ans = INT_MAX;
        for(int i = 0; i < n; i++) {
            //cout << i << " " << dp[i][m] << nl;
            if(dp[i][1] < ans) {
                ans = dp[i][1];
                path = findPath(i);
            } else if(dp[i][1] == ans) {
                vector<int> check = findPath(i);
                if(check < path) {
                    path = check;
                }
            }
        }
        for(int i = 0; i < m; i++) {
            cout << path[i]+1;
            if(i < m-1) cout << " ";
        }
        cout << nl;
        cout << ans << nl;
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

