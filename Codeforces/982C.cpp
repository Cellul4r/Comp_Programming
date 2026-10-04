/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
vector<int> adj[N];
int cnt[N];
int dfs1(int u, int p) {
    int c = 1;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        c += dfs1(v, u);
    }
    cnt[u] = c;
    return c;
}
int dfs2(int u, int p) {
    // the subtree always contain even numbers at root u
    int odd = 0;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        if(cnt[v] % 2 == 1) {
            odd++;
        }
    }
    int ans = 0;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        if(cnt[v] % 2 == 0) {
            // correct answer
            ans++;
            ans += dfs2(v, u);
        } else if(cnt[v] % 2 == 1) {
            ans += dfs2(v, u);
        }
    }
    return ans;
}
void solve(){
    
    int n; cin>>n;
    for(int i = 0; i < n - 1; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n % 2 == 1) {
        cout << -1 << nl;
        return;
    }
    dfs1(1, 0);
    int ans = dfs2(1,0);
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

