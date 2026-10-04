/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+2;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n;
vector<int> adj[N];
double dfs(int u, int p) {
    double x = adj[u].size() - (p != 0);
    double ans = 0;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        ans += (dfs(v, u) + 1) / x;
    }
    //cout << u << " " << ans << nl;
    return ans;
}
void solve(){
    cin>>n;
    for(int i = 0; i < n - 1; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    double ans = dfs(1, 0);
    cout << fixed << setprecision(10) << ans << nl;
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

