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

vector<pi> adj[N];
bool vis[N];

ll dfs(int u, int now, ll ans) {
    
    vis[u] = true;

    ll k = ans;
    for(auto &vd : adj[u]) {
        if(vis[vd.first]) continue;
        if(vd.second < now) {
            cerr << u + 1 << " " << vd.first + 1 << nl;
            k = max(k, dfs(vd.first, vd.second, ans + 1));
        } else {
            k = max(k, dfs(vd.first, vd.second, ans));
        }
    }

    return k;
}
void solve(){
    
    int n;
    cin>>n;

    for(int i = 0; i < n; i++) {
        vis[i] = false;
        adj[i].clear();
    }
    for(int i = 0; i < n - 1; i++) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(make_pair(v,i));
        adj[v].push_back(make_pair(u,i));
    }

    ll ans = 1;
    cout << dfs(0, -1, ans) << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

