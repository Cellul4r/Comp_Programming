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

int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
void solve(){
    
    int n,m;
    cin>>n>>m;

    int ones = 0;
    vector<vector<int>> board(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        string s;
        cin>>s;
        for(int j = 0; j < m; j++) {
            board[i][j] = s[j] - '0';
            if(board[i][j] == 1) ones++;
        }
    }

    int mn = INF;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < m - 1; j++) {
            int cnt = board[i][j] + board[i+1][j] + board[i][j+1] + board[i+1][j+1];
            if(cnt == 0) continue;
            mn = min(mn, max(1, cnt - 1));
        }
    }
    // 1 is from first step we have to do to make subgrid 2x2 has atleast two 0 in subgrid
    if(ones == 0) cout << 0 << nl;
    else cout << 1 + ones - mn << nl;
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

