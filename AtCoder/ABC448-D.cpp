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
int n;
vector<int> adj[N];
int ans[N], a[N];
multiset<int> now;
void dfs(int u, int p, bool has = false) {
    if(now.count(a[u]) || has) {
        ans[u] = 1;
        has = true;
    }
    now.insert(a[u]);
    for(auto &v : adj[u]) {
        if(v == p) continue;
        dfs(v, u, has);
    }
    now.erase(now.find(a[u]));
}
void solve(){

    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i]; 
    }
    for(int i = 0; i < n - 1; i++) {
        int u,v; cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    for(int i = 0; i < n; i++) {
        cout << (ans[i] ?  "Yes" : "No") << nl;
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

