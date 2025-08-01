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
const int N =15;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n;
int board[N][N];
bool vis[10];
int valid[10];
int cnt[N][N];
void solve(){
    
    cin>>n;
    for(int i = 0; i < n; i++) {
        string s;
        cin>>s;
        for(int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0';
            valid[board[i][j]] = true;
            vis[board[i][j]] = true;
        }
    }

    for(int i = 1; i <= 9; i++) {
        if(!vis[i]) {
            continue;
        }
        int l = n - 1, r = 0, u = n - 1, d = 0;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(board[j][k] == i) {
                    l = min(l,k);
                    r = max(r,k);
                    u = min(u,j);
                    d = max(d,j);
                }
            }
        }

        for(int j = u; j <= d; j++) {
            for(int k = l; k <= r; k++) {
                cnt[j][k]++;
            }
        }
    }

    for(int i = 1; i <= 9; i++) {
        if(!vis[i]) continue;
        int l = n - 1, r = 0, u = n - 1, d = 0;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(board[j][k] == i) {
                    l = min(l,k);
                    r = max(r,k);
                    u = min(u,j);
                    d = max(d,j);
                }
            }
        }

        for(int j = u; j <= d; j++) {
            for(int k = l; k <= r; k++) {
                if(cnt[j][k] > 1 && board[j][k] == i) {
                    valid[i] = false;
                }
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= 9; i++) {
        if(valid[i]) ans++;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

