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
    
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    int ans = INF;
    vector<array<int,2>> b;
    vector<int> deg(n+1);
    for(int i = 1; i <= m; i++) {
        int u,v; cin>>u>>v;
        b.push_back({u,v});
        deg[u]++;
        deg[v]++;
    }
    if(m % 2 == 0) {
        cout << 0 << nl;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(deg[i] % 2 == 1) {
            ans = min(ans, a[i]);
        }
    }
    for(auto &x : b) {
        if(deg[x[0]] % 2 == 0 && deg[x[1]] % 2 == 0) {
            ans = min(ans, a[x[0]] + a[x[1]]);
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

