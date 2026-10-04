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
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
vector<int> adj[N];
int color[N];
bool ok = true;
int black = 0, white = 0;
void dfs(int u, int c) {
    color[u] = c;
    black += (c == 1);
    white += (c == 2);
    for(auto &v : adj[u]) {
        if(color[v] == 0) {
            dfs(v, (c == 1 ? 2 : 1));
        } else if(color[v] == c) {
            ok = false;
        }
    }
}
void solve(){
    
    int n,m; cin>>n>>m; 
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        color[i] = 0;
    }
    for(int i = 1; i <= m; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // the component of undi graph must not contain odd length cycle (bipartile graph)
    // if not then how to assign them?
    //  
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(color[i] != 0) continue;
        ok = true;
        black = white = 0;
        dfs(i,1);
        if(ok) {
            ans += max(black, white);
        }
    }
    cout << ans << nl;
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

