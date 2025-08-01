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
const int N =1e6+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n,m;
int component[N], par[N], rnk[N];
vector<pair<pi,int>> a;
bool vis[N];

int find(int u) {
    if(u == par[u]) return u;
    return par[u] = find(par[u]);
}

void merge(int u, int v) {
    u = find(u), v = find(v);
    if(u == v) return;
    if(rnk[u] < rnk[v]) {
        par[u] = v;
        rnk[v] += rnk[u];
    } else {
        par[v] = u; 
        rnk[u] += rnk[v];
    }
}
void solve(){
    cin>>n>>m;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        int x,y;
        cin>>x>>y;
        a[i] = make_pair(make_pair(x,y),i);
        par[i] = i;
        rnk[i] = 1;
    }

    sort(all(a));
    for(int i = 0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        //adj[u].push_back(v);
        //adj[v].push_back(u);
        merge(u,v);
    }

    int ans = 0;
    int k = find(a[0].second);
    for(int i = 1; i < n; i++) {
        int x = find(a[i].second); 
        if(k == x) continue;
        if(rnk[k] > i) {
            ans++;
        }
        merge(k,x);
        k = find(x);
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    //cin>>t;
    while(t--)solve();

    return 0;
}

