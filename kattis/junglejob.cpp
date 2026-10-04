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
ll dp[N][N], dp2[N], sz[N];
vector<int> adj[N];

void add(ll& a, ll b) {
    a += b;
    if(a >= INF) a -= INF;
}

void dfs(int u) {
    // dp on tree
    dp[u][1] = 1;
    sz[u] = 1;

    for(auto &v : adj[u]) {
        dfs(v);

        memset(dp2, 0, sizeof dp2);
        for(int i = 1; i <= sz[u]; i++) {
                
            // not include any of subtree v
            add(dp2[i], dp[u][i]);

            // include subtree v of size j 
            for(int j = 1; j <= sz[v]; j++) {
                add(dp2[i+j], (dp[u][i] * dp[v][j]) % INF);
            }
        }

        sz[u] += sz[v];
        for(int i = 1; i <= sz[u]; i++) {
            dp[u][i] = dp2[i];
        }
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i = 1; i < n; i++) {
        int p; cin>>p;
        adj[p].push_back(i);
    }

    dfs(0);
    for(int i = 1; i <= n; i++) {
        ll s = 0;
        for(int j = 0; j < n; j++) {
            add(s, dp[j][i]);
        }
        cout << s << nl;
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

