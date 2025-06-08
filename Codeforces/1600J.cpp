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
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
const int dr[] = {0,1,0,-1}, dc[] = {-1,0,1,0};
void solve(){
    
    int n,m;
    cin>>n>>m;

    auto conv = [&](int i, int j) {
        return i * m + j;
    };

    vector<vector<int>> a(n, vector<int>(m));
    vector<int> rnk(n*m), par(n*m);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>a[i][j];
            rnk[conv(i,j)] = 1;
            par[conv(i,j)] = conv(i,j);
        }
    }

    function<int(int)> findPar = [&](int u) {
        if(u == par[u]) return u;
        return par[u] = findPar(par[u]);
    };
    auto merge = [&](int u, int v) {
        u = findPar(u), v = findPar(v);
        if(u == v) return;
        if(rnk[u] < rnk[v]) swap(u,v);
        rnk[u] += rnk[v];
        par[v] = u;
    };

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            for(int k = 0; k < 4; k++) {
                if((1 << k) & a[i][j]) continue;
                int u = conv(i,j);
                int vr = i + dr[k], vc = j + dc[k];
                int v = conv(vr,vc);
                //cerr << u << " " << v << nl;
                merge(u,v);
            }
        }
    }
    vector<bool> vis(n*m);
    vector<int> ans;
    for(int i = 0; i < n * m; i++) {
        int u = findPar(i);
        if(vis[u]) continue;
        vis[u] = true;
        ans.push_back(rnk[u]);
    }
    sort(all(ans));
    reverse(all(ans));
    for(auto &x : ans) cout << x << " ";
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

