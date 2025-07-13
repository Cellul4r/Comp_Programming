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
const int N =4e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);

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
    
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        vis[i] = false;
    }
    int ans = 1;
    vector<int> a(n+1), b(n+1); 
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        a[i] = x;
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        b[i] = x;
    }
    
    for(int i = 0; i < n; i++) {
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(!vis[i]) {
            dfs(i);
            ans = ans * 2 % INF;
        }
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

