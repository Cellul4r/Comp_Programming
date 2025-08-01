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
const int N =11;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n, board[N][N]; 
void solve(){
    
    cin>>n;
    for(int i = 0; i < n; i++) {
        string s;
        cin>>s;
        for(int j = 0; j < n; j++) {
            board[i][j] = s[j] - '0';
        }
    }

    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 0; j--) {
            if(board[i][j]) {
                ans++;
                for(int r = 0; r <= i; r++) {
                    for(int c = 0; c <= j; c++) {
                        board[r][c] ^= 1;
                    }
                }
            }
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

