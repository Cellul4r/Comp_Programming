/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =2e5+100;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
bool vis[N];
vector<int> adj[N];
void dfs(int u, int p = 0) {
    vis[u] = true;
    for(auto &v : adj[u]) {
        if(v == p || vis[v]) continue;
        dfs(v, u);
    }
}
void solve(){
    
    int n;
    cin>>n;
    
    // the answer is the number of connected component in the graph.
    // how can we find it with O(n)?
    // suppose sort the string by the length descending order
    // this most length will be the change to equivalent smaller string so we don't have to process smaller strings again
    // but how can we mark smaller strings
    for(int i = 1; i <= n; i++) {
        string s; cin>>s;
        vector<bool> save(26, false);
        for(auto &x : s) {
            save[x-'a'] = true;
        }
        for(int j = 0; j < 26; j++) {
            if(save[j]) {
                adj[i+26].push_back(j);
                adj[j].push_back(i+26);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        if(vis[i] || adj[i].size() == 0) continue;
        ans++;
        dfs(i);
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

