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
const int dr[] = {-1,-1,1,1}, dc[] = {-1,1,1,-1};
void solve(){
    
    int n,m; cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> b(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>a[i][j];
        }
    }

    bool bad = false;
    vector<array<int,2>> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] == b[i][j]) continue;
            // 4 directions
            // -1, -1
            // -1, 1
            // 1, 1
            // 1, -1
            bool found = false;
            for(int k = 0; k < 4; k++) {
                bool ok = true;
                for(int x = 0; x <= 1; x++) {
                    for(int y = 0; y <= 1; y++) {
                        int ni = i + x * dr[k], nj = j + y * dc[k];
                        if(ni < 0 || nj < 0 || ni >= n || nj >= m || a[ni][nj] == 0) {
                            ok = false;
                        }
                    }
                }
                if(ok) {
                    found = true;
                    for(int x = 0; x <= 1; x++) {
                        for(int y = 0; y <= 1; y++) {
                            int ni = i + x * dr[k], nj = j + y * dc[k];
                            b[ni][nj] = 1;
                        }
                    }
                    if(k == 0) {
                        ans.push_back({i-1,j-1});
                    } else if(k == 1) {
                        ans.push_back({i-1,j});
                    } else if(k == 2) {
                        ans.push_back({i,j});
                    } else {
                        ans.push_back({i,j-1});
                    }
                    break;
                }
            }
            if(!found) {
                bad = true;
            }
        }
    }
    if(bad) {
        cout << -1;
        return;
    }
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x[0] + 1 << " " << x[1] + 1 << nl;
    }
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

