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
    
    int n; cin>>n;
    vector<int> adj[n+1];
    vector<int> deg(n+1);
    for(int i = 0; i < n - 1; i++) {
        int u,v; cin>>u>>v;
        deg[u]++;
        deg[v]++;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(n <= 2) {
        cout << 0 << nl;
        return;
    }
    int leaves = 0;
    for(int i = 1; i <= n; i++) leaves += (deg[i] == 1);
    int mx = 0;
    for(int i = 1; i <= n; i++) {
        // select root
        int k = 0;
        for(auto &u : adj[i]) {
            if(deg[u] == 1) k++;
        }
        mx = max(mx,k);
    }
    cout << leaves - mx << nl;
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

