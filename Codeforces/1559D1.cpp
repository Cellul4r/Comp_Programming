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
const int N =1e3+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
struct tree {
    
    int par[N];
    int rnk[N];

    void init(int n) {
        for(int i = 1; i <= n; i++) {
            par[i] = i;
            rnk[i] = 1;
        }
    }

    int findPar(int u) {
        if(u == par[u]) return u;
        return par[u] = findPar(par[u]);
    }

    bool merge(int u, int v) {
        u = findPar(u), v = findPar(v);
        if(u == v) return false;
        if(rnk[u] < rnk[v]) swap(u,v);
        par[v] = u;
        rnk[u] += rnk[v];
        return true;
    }
};
void solve(){
    
    int n,m1,m2;
    cin>>n>>m1>>m2;
    assert(n <= 1000);
    tree a,b; 
    a.init(n), b.init(n);
    for(int i = 0; i < m1; i++) {
        int u,v;
        cin>>u>>v;
        a.merge(u,v);
    }

    for(int i = 0; i < m2; i++) {
        int u,v;
        cin>>u>>v;
        b.merge(u,v);

    }

    vector<pi> ans;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a.findPar(i) != a.findPar(j) && b.findPar(i) != b.findPar(j)) {
                a.merge(i,j);
                b.merge(i,j);
                ans.push_back(make_pair(i,j));
            }
        }
    }

    cout << ans.size() << nl;
    for(auto &[x, y] : ans) {
        cout << x << " " << y << nl;
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

