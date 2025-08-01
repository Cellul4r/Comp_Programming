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
const int N =401;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n,k;
ll board[2*N+1][2*N+1];
int m;
ll ans = 0;
void solve(){
    cin>>n>>k; 
    m = 2 * n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin>>board[i+j-1][-i+j+n];
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            board[i][j] += board[i-1][j] + board[i][j-1] - board[i-1][j-1];
        }
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++) {
            int r = min(m, i + 2 * k);
            int c = min(m, j + 2 * k);
            ans = max(ans, board[r][c] - board[i-1][c] - board[r][j-1] + board[i-1][j-1]);
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    ///*
    string s = "lazy";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    //*/

    //cin>>t;
    while(t--)solve();

    return 0;
}

