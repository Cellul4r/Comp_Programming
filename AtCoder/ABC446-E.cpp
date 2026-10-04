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
const int N =1e3+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
vector<array<int,2>> adj[N][N];
bool vis[N][N];
void solve(){
    
    int m,a,b; cin>>m>>a>>b;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            int k = (a * j + b * i) % m;
            adj[j][k].push_back({i,j});
            // j * m + k, // i * m + k
            // i.e. to reduce to array 1D, (i,j) -> i * m + j
        }
    }

    queue<array<int,2>> Q;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(i != 0 && j != 0) continue;
            vis[i][j] = true;
            Q.push({i,j});
        }
    }

    while(!Q.empty()) {
        auto now = Q.front();
        Q.pop();
        for(auto &v : adj[now[0]][now[1]]) {
            if(vis[v[0]][v[1]]) continue;
            vis[v[0]][v[1]] = true;
            Q.push(v);
        }
    }

    int ans = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j]) {
                ans++;
            }
        }
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

