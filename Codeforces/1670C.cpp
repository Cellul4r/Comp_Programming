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
void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n), b(n),c(n);
    vector<int> par(n), rnk(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        a[i]--;
        par[i] = i;
        rnk[i] = 1;
    }
    for(int i = 0; i < n; i++) {
        cin>>b[i];
        b[i]--;
    }
    for(int i = 0; i < n; i++) {
        cin>>c[i];
        c[i]--;
    }
    int ans = 1;

    vector<bool> vis(n);
    for(int i = 0; i < n; i++) {
        if(c[i] == -1) continue;
        vis[c[i]] = true;
    }
    
    function<int(int)> findPar = [&](int u) {
        if(u == par[u]) return u;
        return par[u] = findPar(par[u]);
    };

    auto merge = [&](int u, int v) {
        u = findPar(u), v = findPar(v);
        if(u == v) return false;
        if(rnk[u] < rnk[v]) swap(u,v);
        rnk[u] += rnk[v];
        par[v] = u;
        return true;
    };
    for(int i = 0; i < n; i++) {
        if(c[i] != -1) continue;
        //cerr << i << nl;
        if(vis[a[i]] || vis[b[i]]) continue;
        if(a[i] == b[i]) continue;
        if(!merge(a[i],b[i])) ans = ans * 2 % INF;
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

