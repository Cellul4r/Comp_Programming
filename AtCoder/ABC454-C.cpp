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
const int N =3e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
bool vis[N];
vector<int> adj[N];
void solve(){
    
    int n,m; 
    cin>>n>>m;
    for(int i = 1; i <= m; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
    }

    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(auto &v : adj[u]) {
            if(vis[v]) continue;
            vis[v] = true;
            Q.push(v);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) ans++;
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

