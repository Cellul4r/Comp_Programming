#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
typedef long long ll;
int n;
vector<int> adj[N];
int sz[N];
int a[N];
int dfs(int u, int p) {
    int ans = 1;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        ans += dfs(v,u);
    }
    return sz[u] = ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin>>x;
        if(x == 0) continue;
        a[i] = x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            dfs(i,0);
        }
    }
    int idx = -1, freq = 0;
    for(int i = 1; i <= n; i++) {
        if(sz[i] > freq) {
            freq = sz[i];
            idx = i;
        }
    }
    cout << idx << " " << freq;
    return 0;
}
