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
const int N =50;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int m,n;
int cnt = 0;
int a[N][N], color[N];
bool vis[N][N];
bool cycle[N];
int recur(int u, int v) {
    if(u == v) return 1;

    int ans = 0;
    for(int k = 0; k < n; k++) {
        if(a[u][k] == 0) continue;
        if(!vis[u][k]) {
            vis[u][k] = true; 
            ans += recur(k,v);
            vis[u][k] = false;
        }
    }
    return ans;
}

bool dfs(int u) {
    if(color[u] == 1) {
        return true;
    }
    if(color[u] == 2) {
        return false;
    }
    color[u] = 1;
    for(int v = 0; v < n; v++) {
        if(a[u][v] && dfs(v)) {
            return true;
        }
    }
    color[u] = 2;
    return false;
}
void solve(){

    while(cin>>m) {
        n = 0;
        memset(a, 0, sizeof a);
        memset(vis, false, sizeof vis);
        memset(cycle, false, sizeof cycle);
        for(int i = 0; i < m; i++) {
            int u,v;
            cin>>u>>v;
            n = max(n,u);
            n = max(n,v);
            a[u][v] = 1;
        }
        n++;
        cout << "matrix for city " << cnt++ << nl;

        for(int i = 0; i < n; i++) {
            memset(color, 0, sizeof color);
            if(dfs(i)) {
                cycle[i] = true;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(cycle[i] && recur(i,j) > 0) {
                    cout << -1;
                } else if(i == j) {
                    cout << 0;
                } else {
                    cout << recur(i,j);
                }
                if(j < n - 1) cout << " ";

            }
            cout << nl;
        }
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

