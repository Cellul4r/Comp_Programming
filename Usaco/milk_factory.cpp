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
const int N =100+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n;
vector<int> adj[N];
bool vis[N];
void dfs(int u) {
    vis[u] = true;
    for(auto &v : adj[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}
void solve(){
    
    cin>>n;
    for(int i = 0; i < n - 1; i++) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        // reverse the direction
        adj[v].push_back(u);
    }

    for(int i = 0; i < n; i++) {
        // i is center that can go through any other vertexs
        // because we have reversed the direction!
        // can go through any other vertexs only if dfs only 1 times
        bool flag = true;
        for(int i = 0; i < n; i++) vis[i] = false;
        dfs(i);
        for(int j = 0; j < n; j++) {
            if(!vis[j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << i + 1;
            return;
        }
    }
    cout << -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("factory.in", "r", stdin);
    freopen("factory.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

