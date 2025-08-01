#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
const int N = 1e5+1;
int adj[N][2];
int a[N];
bool vis[N];
int cnt[(int)(1e6+1)];
void dfs(int u) {
    vis[u] = true;
    cnt[a[u]]++;
    for(auto &v : adj[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
}
void solve() {
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) {
        int u,v;
        cin>>u>>v;
        adj[i][0] = u;
        adj[i][1] = v;
    }
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    dfs(1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
