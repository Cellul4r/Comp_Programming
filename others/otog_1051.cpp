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
const int N =2001;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n,m,q;
int x,y,k;
char board[N][N];
const int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
void solve(){
    
    cin>>n>>m>>q;     
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            board[i][j] = '.';
        }
    }
    for(int i = 0; i < q; i++) {
        int r,c,k;
        cin>>r>>c>>k;
        board[r][c] = '#';
        for(int j = -k; j <= k; j++) {
            int now = k - abs(j);
            //cerr << now << nl;
            for(int l = -now; l <= now; l++) {
                if(r + j < 0 || r + j >= n || c + l < 0 || c + l >= m) continue;
                //cerr << r + j << " " << c + l << nl;
                if(board[r+j][c+l] != '#') board[r+j][c+l] = '*';
            }
            //cout << nl;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << board[i][j];
        }
        cout << nl;
    }
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

