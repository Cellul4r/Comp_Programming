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
const int N =2e5+5;
const int INF = 998244353;
const ll LINF = 1e18+7;

void setIO(string);
int par[N];
int ans[N];
int pow2[N];

int f(int u) {
    if(u == par[u]) return u;
    return par[u] = f(par[u]);
}
void merge(int u, int v) {
    u = f(u), v = f(v); 
    if(u == v) return;

    par[v] = u;
}
void solve(){
    
    int n,m; cin>>n>>m;
    pow2[0] = 1;
    for(int i = 1; i <= m; i++) {
        pow2[i] = (2 * pow2[i-1]) % INF;
    }
    for(int i = 0 ; i< n; i++) par[i] = i;
    vector<pi> a;
    for(int i = 0; i < m; i++) {
        int u,v; cin>>u>>v;
        u--,v--;
        a.push_back({u,v});
    }
    int cur = n;
    for(int i = m - 1; i >= 0; i--) {
        int u = a[i].first, v = a[i].second;
        if(f(u) == f(v)) {
            continue;
        }
        if(cur > 2) {
            merge(u,v);
            cur--;
        } else {
            ans[i+1] = 1;
        }
    }
    int k = 0;
    for(int i = 0; i <= m; i++) {
        if(ans[i] == 0) continue;
        k  = (k + pow2[i]) % INF;
    }
    cout << k;
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

