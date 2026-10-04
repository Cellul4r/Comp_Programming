/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
vector<int> adj[N];
int comp[N];
int sz[N];
int d[N];
int a[N], b[N];
void dfs(int u, int id, int& len) {
    comp[u] = id;
    len++;
    for(auto &v : adj[u]) {
        if(comp[v] == -1) {
            d[v] = d[u] + 1;
            dfs(v, id, len);
        }
    }
}
void solve(){
    
    int n,K;
    cin>>n>>K;
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        comp[i] = -1;
        d[i] = 0;
        sz[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        adj[i].push_back(a[i]);
    }
    for(int i = 1; i <= n; i++) {
        cin>>b[i];
    }

    vector<int> lens;
    vector<vector<int>> cnt(n+1);
    for(int i = 1, id = 1; i <= n; i++) {
        if(comp[i] == -1) {
            int len = 0;
            dfs(i, id, len);
            sz[id] = len;
            id++;
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(comp[i] == comp[b[i]]) {
            int len = sz[comp[i]];
            int val = (d[b[i]] - d[i] + len) % len;

            if(cnt[len].empty()) {
                cnt[len].assign(len+1, 0);
                lens.push_back(len);
            }
            cnt[len][val]++;
        }
    }

    int ans = 0;
    for(int i = 1; i <= K; i++) {
        int cur = 0;
        for(auto &len : lens) {
            cur += cnt[len][i % len];
        }
        ans = max(ans, cur);
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

