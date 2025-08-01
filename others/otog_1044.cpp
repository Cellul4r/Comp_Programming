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
const int N =101;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n,m,k;
int board[N*N][N];
bool vis[N*N][N];
const int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
int dfs(int start, int i, int j) {

    vis[i][j] = true;
    //cerr << i << " " << j << " " << start << nl;
    int cnt = (board[i][j] == 2);
    for(int l = 0; l < 4; l++) {
        int ni = i + dr[l];
        int nj = j + dc[l];
        //cerr << ni << " " << nj << nl;

        if(ni < start || nj < 0 || ni >= (start + 1) * n || nj >= m || vis[ni][nj] || board[ni][nj] == 0) continue;
        cnt += dfs(start, ni, nj);
    }
    return cnt;
}
void solve(){
    
    cin>>k>>n>>m;
    for(int i = 0; i < n * k; i++) {
        string s;
        cin>>s;
        for(int j = 0; j < m; j++) {
            if(s[j] == '#') {
                board[i][j] = 0;
            } else if(s[j] == '.') {
                board[i][j] = 1;
            } else {
                board[i][j] = 2;
            }
        }
    }

    vector<int> level;
    for(int i = 0; i < k; i++) {
        int maxCnt = 0;
        //cerr << i << "TEST" << nl;
        for(int j = i * n; j < (i + 1) * n; j++) {
            for(int l = 0; l < m; l++) {
                if(vis[j][l] || !board[j][l]) continue;
                maxCnt = max(maxCnt, dfs(i, j, l));
            }
        }
        level.push_back(maxCnt);
        //cerr << "COunt : " << maxCnt << nl;
    }
    sort(all(level));
    reverse(all(level));
    for(int i = 1; i < (int)level.size(); i++) level[i] += level[i-1];
    int q;
    cin>>q;
    for(int i = 0; i < q; i++) {
        int r;
        cin>>r;
        auto it = lower_bound(all(level), r);
        if(it == level.end()) {
            cout << -1 << nl;
            continue;
        }
        cout << (it - level.begin()) + 1 << nl;
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

