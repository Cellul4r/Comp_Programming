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
int par[N];
ll a[N], sz[N];
void dfs(int u, int p=0) {
    par[u] = p;
    sz[u] = 1;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}
void solve(){
    
    int n; cin>>n;
    // 1 -> 1 * 1 * 1
    // 4 -> 1 * 1 * 4, 1 * 2 * 2,
    // 9 -> 1 * 1 * 9, 1 * 3 * 3,
    // check if that vertice v has the value of x^3 perfect square or not
    //
    for(int i =1; i<=n; i++) {
        adj[i].clear();
        cin>>a[i];
    }
    for(int i =1 ; i<= n-1;i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    ll ans = 0;
    auto f = [&](ll p, ll p2, ll p3) {
        return (p * p * p - 3ll*p*p2 + 2ll*p3) / 6ll; 
    };
    for(int i = 1; i <= n; i++) {
        ll x = sqrt(a[i]);
        // sqrt(a[i]^3) = a[i]sqrt(a[i])
        if(x * x != a[i]) continue;
        ll p = 1, p2 = 1, p3 = 1;
        for(auto &v : adj[i]) {
            ll cur;
            if(par[i] == v) {
                cur = n - sz[i];
            } else {
                cur = sz[v];
            }
            p += cur;
            p2 += cur * cur;
            p3 += cur * cur * cur;
        }
        ans += f(p,p2,p3); 
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

