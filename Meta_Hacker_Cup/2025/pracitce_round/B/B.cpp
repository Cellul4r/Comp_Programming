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
int n,m,s;
int dfs(int ur, int uc, vector<vector<bool>>& vis, vector<vector<ll>>& level) {

    vis[ur][uc] = true;
    int ans = 1;
    for(int k = 0; k < 4; k++) {
        int vr = ur + dr[k], vc = uc + dc[k];
        if(vr < 0 || vc < 0 || vr >= n || vc >= m || vis[vr][vc] || level[vr][vc] < s) continue;
        ans += dfs(vr,vc,vis,level);
    }
    return ans;
}
void solve(){

    cin>>n>>m>>s;
    s++;
    // find area such that to this safe cell is >= s + 1 from bfs traversal
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<ll>> level(n, vector<ll>(m,-1));

    queue<pi> Q;
    for(int i = 0; i < n; i++) {
        string ss;
        cin>>ss;
        for(int j = 0; j < m; j++) {
            if(ss[j] == '.') continue;
            a[i][j] = 1;
            level[i][j] = 0;
            Q.push(make_pair(i,j));
        }
    }

    for(int i = 0; i < n; i++) {
        if(a[i][0] == 0) {
            level[i][0] = 1;
            Q.push(make_pair(i,0));
        }
        if(a[i][m-1] == 0) {
            level[i][m-1] = 1;
            Q.push(make_pair(i,m-1));
        }
    }
    for(int i = 0; i < m; i++) {
        if(a[0][i] == 0) {
            level[0][i] = 1;
            Q.push(make_pair(0,i));
        }
        if(a[n-1][i] == 0) {
            level[n-1][i] = 1;
            Q.push(make_pair(n-1,i));
        }
    }
    
    while(!Q.empty()) {
        int ur = Q.front().first, uc = Q.front().second;
        Q.pop();

        for(int k = 0; k < 4; k++) {
            int vr = ur + dr[k], vc = uc + dc[k];
            if(vr < 0 || vc < 0 || vr >= n || vc >= m || level[vr][vc] != -1) continue;
            level[vr][vc] = level[ur][uc] + 1;
            Q.push(make_pair(vr,vc));
        }
    }

    vector<vector<bool>> vis(n, vector<bool>(m));
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            //cout << level[i][j] << " ";
            if(vis[i][j] || level[i][j] < s) continue;
            ans = max(ans, dfs(i,j,vis,level));
        }
        //cout << nl;
    }

    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

