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
const int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
int n,m;
vector<vector<int>> board;
vector<vector<int>> level;
void solve(){

    cin>>n>>m;
    board.resize(n, vector<int>(m));
    level.resize(n, vector<int>(m));
    queue<array<int,3>> Q;
    for(int i = 0; i < n; i++) {
        string s; cin>>s;
        for(int j = 0; j < m; j++) {
            level[i][j] = -1;
            if(s[j] == '#') {
                board[i][j] = 1;
                level[i][j] = 0;
                Q.push({i,j,0});
            }
        }
    }
    
    while(!Q.empty()) {
        int ur = Q.front()[0], uc = Q.front()[1], val = Q.front()[2];
        Q.pop();
        for(int k = 0; k < 4; k++) {
            int vr = ur + dr[k], vc = uc + dc[k];
            if(vr < 0 || vc < 0 || vr >= n || vc >= m) continue;
            if(level[vr][vc] != -1) continue;
            int cnt = 0;
            for(int l = 0; l < 4; l++) {
                int xr = vr + dr[l], xc = vc + dc[l];
                if(xr < 0 || xc < 0 || xr >= n || xc >= m) continue;
                cnt += (level[xr][xc] != -1 && level[xr][xc] <= val);
            }
            if(cnt != 1) continue;
            level[vr][vc] = level[ur][uc] + (level[vr][vc] == -1 ? 1 : 0);            
            Q.push({vr,vc,level[vr][vc]});
        }
    }
    
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(level[i][j] != -1) ans++;
            //cerr << level[i][j] << " ";
        }
        //cerr << nl;
    }
    cout << ans;
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

