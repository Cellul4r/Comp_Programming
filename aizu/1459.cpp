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
const int N =55;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
const int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
int n,m; 
bool vis[N][N];
char board[N][N];
int sr,sc;
ll recur(int i, int j) {
     
    vis[i][j] = true;
    char& c = board[i][j];
    if(c >= '0' && c <= '9') {
        return c - '0';
    }
    
    ll ans = -1;
    // not a number
    if(c == '#' || c == 'P') {
        // 1 ways that is not . and not vis yet
        for(int k = 0; k < 4; k++) {
            int ni = i + dr[k], nj = j + dc[k];
            if(ni < 1 || nj < 1 || ni > n || nj > m || vis[ni][nj] || board[ni][nj] == '.') continue;
            ans = recur(ni,nj);
        }
    } else {
        ll left = -1, right = -1;
        for(int k = 0; k < 4; k++) {
            int ni  = i + dr[k], nj = j + dc[k];
            if(ni < 1 || nj < 1 || ni > n || nj > m || vis[ni][nj] || board[ni][nj] == '.') continue;
            if(left == -1) {
                left = recur(ni,nj);
            } else {
                right = recur(ni,nj);
            }
        }
        if(left < right) swap(left, right);
        if(c == '+') {
            ans = left + right;
        } else if(c == '-') {
            ans = left - right;
        } else if(c == '*') {
            ans = left * right;
        } else if(c == '/'){
            ans = left / right;
        } else {
            assert(false);
        }
    }

    return ans;
}
void solve(){
    
    cin>>n>>m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin>>board[i][j];
            if(board[i][j] == 'P') {
                sr = i;
                sc = j;
            }
        }
    }

    ll ans = recur(sr,sc);
    cout << ans << nl;
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

