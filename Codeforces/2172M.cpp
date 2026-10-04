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
int n,m,k;
int a[N];
vector<int> adj[N];
int ans[N], level[N];
void solve(){
    
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        level[i] = -1;
    }

    for(int i = 1; i <= m; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> Q;
    Q.push(1);
    level[1] = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(auto &v : adj[u]) {
            if(level[v] != -1) continue;
            level[v] = level[u] + 1;
            ans[a[v]] = max(ans[a[v]],level[v]);
            Q.push(v);
        }
    }

    for(int i = 1; i <= k; i++) {
        cout << ans[i] << " ";
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

