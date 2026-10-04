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
const int N =22;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int a[N];
int cur[N];
int aa[N], curr[N];
int n;
int LCS() {
    vector<vector<int>> dp(n+1,vector<int>(n+1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i-1] == cur[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][n];
}
void solve(){
    
    string line;
    while(getline(cin,line)) {
        // input n
        stringstream ss(line);
        int x,y;
        ss>>x;
        if(!(ss>>y)) {
            // input n
            n = x;
            for(int i = 0; i < n; i++) {
                cin>>aa[i];
            }
            for(int i = 0; i < n; i++) {
                a[aa[i] - 1] = i + 1;
            }
            // ignore new line to be no error on getline
            cin.ignore();
        } else {
            // correct order
            curr[0] = x;
            curr[1] = y;
            for(int i = 2; i < n; i++) {
                ss>>curr[i];
            }
            for(int i = 0; i < n; i++) {
                cur[curr[i] - 1] = i + 1;
            }
            cout << LCS() << nl;
        }
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

