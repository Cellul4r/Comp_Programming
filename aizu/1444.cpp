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
const int N =1e2+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
const int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
ll ans = 0;
int n,m;
string a = "YOKOHAMA";
string board[N];
void recur(int i, int j, int k) {
    if(k == 8) {
        ans++;
        return;
    }

    for(int l = 0; l < 4; l++) {
        int ni = i + dr[l];
        int nj = j + dc[l];
        if(ni < 0 || nj < 0 || ni >= n || nj >= m || a[k] != board[ni][nj]) continue;
        recur(ni,nj,k+1);
    }
}
void solve(){

    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        cin>>board[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] != a[0]) continue;
            recur(i,j,1);
        }
    }
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

