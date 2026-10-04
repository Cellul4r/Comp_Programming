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
void solve(){
    
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<pi> ord(n*m+1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>a[i][j];
            ord[a[i][j]] = make_pair(i,j);
        }
    }

    auto f = [&](int r, int c, int tr, int tc) {
        int diff1 = INF, diff2 = INF;

        pi now;
        for(int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if(abs(a[nr][nc] - a[tr][tc]) < diff1) {
                diff1 = abs(a[nr][nc] - a[tr][tc]);
                diff2 = abs(a[r][c] - a[nr][nc]);
                now.first = nr;
                now.second = nc;
            } else if(abs(a[nr][nc] - a[tr][tc]) == diff1 && diff2 > abs(a[r][c] - a[nr][nc])) {
                diff2 = abs(a[r][c] - a[nr][nc]);
                now.first = nr;
                now.second = nc;
            }
        }
        return now;
    };
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(n * m + 1, INF)));
    for(int i = 1; i <= n * m; i++) {
        queue<pi> Q;
        int r = ord[i].first, c = ord[i].second;
        dist[r][c][i] = 0;
        Q.push(make_pair(r,c));
        while(!Q.empty()) {
            r = Q.front().first, c = Q.front().second;
            Q.pop();
            for(int k = 0; k < 4; k++) {
                int nr = r + dr[k], nc = c + dc[k];
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if(dist[nr][nc][i] != INF) continue;
                pi now = f(nr,nc,ord[i].first,ord[i].second);
                if(now.first != r || now.second != c) continue;
                dist[nr][nc][i] = dist[r][c][i] + 1;
                Q.push(make_pair(nr,nc));
            }
        }
    }
    int cur = -1, ans = INF;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int mx = -1;
            bool ok = true;
            for(int k = 1; k <= n * m; k++) {
                if(dist[i][j][k] == INF) {
                    ok = false;
                    continue;
                }
                mx = max(mx, dist[i][j][k]);
            }

            if(ans > mx && ok) {
                ans = mx;
                cur = a[i][j];
            }
        }
    }

    if(cur == -1) {
        cout << "impossible";
        return;
    }
    cout << cur << " " << ans;
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

