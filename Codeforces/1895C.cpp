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
ll dp[6][46];
int sum(string& s) {
    int ans = 0; 
    for(auto &x : s) {
        ans += x-'0';
    }
    return ans;
}
void solve(){
    int n; cin>>n; 
    vector<string> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int x = a[i].size(), b = sum(a[i]);
        dp[x][b]++;
    }
    for(int i = 1; i <= n; i++) {
        int x = a[i].size(), b = sum(a[i]);
        for(int j = 1; j <= x; j++) {
            if(j % 2 != x % 2) continue;
            // case 1 i == j
            if(x== j) {
                ans += dp[j][b];
            } else {
                int cut = (x - j) / 2;
                // (x,j)
                int c = 0;
                for(int k = 1; k <= cut; k++) {
                    c += a[i][x-k] - '0';
                }
                if(b - 2 * c >= 0) ans += dp[j][b - 2 * c];
                // (j,x)
                c = 0;
                for(int k = 1; k <= cut; k++) {
                    c += a[i][k-1] - '0';
                }
                if(b - 2 * c >= 0) ans += dp[j][b - 2 * c];
            }
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
   // cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

