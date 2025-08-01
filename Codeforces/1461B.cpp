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

void setIO(string);
void solve(){
    
    int n,m;
    cin>>n>>m;
    vector<string> board(n);
    for(int i = 0; i < n; i++) {
        cin>>board[i];
    }
    ll ans = 0;
    vector<vector<int>> pre(n+1, vector<int>(m+1));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            pre[i+1][j+1] = (board[i][j] == '*' ? 1 : 0);
            pre[i+1][j+1] += pre[i+1][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == '.') continue;
            for(int k = 0; k < n; k++) {
                if(i + k >= n || j - k < 0 || j + k >= m) break;
                if(pre[i+k+1][j+k+1] - pre[i+k+1][j-k] != 2 * k + 1) break;
                ans++;
            }
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

