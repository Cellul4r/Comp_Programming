/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pl;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =2e5+2;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
vector<array<ll,2>> adj[N];
void solve(){
    
    // to travel they don't have many other ways
    // first to go from a to b is the same as b to a? since it is undirected graph
    // true
    // so let u,v and u < v
    // to travel from u to v there aren't many choice in this graph

    int n,q; cin>>n>>q;
    vector<ll> sum(n+2, 0);
    for(int i = 1; i <= n; i++) {
        ll x; cin>>x;
        sum[i+1] += x + sum[i];
        adj[i].push_back({i%n+1,x});
        adj[i%n+1].push_back({i,x});
    }

    for(int i = 1; i <= n; i++) {
        ll x; cin>>x;
        adj[i].push_back({n+1,x});
        adj[n+1].push_back({i,x});
    }

    vector<ll> dist(n+2, LLONG_MAX);
    vector<bool> vis(n+2, false);

    priority_queue<pl, vector<pl>, greater<>> pq;
    dist[n+1] = 0;
    pq.push({dist[n+1],n+1});
    while(!pq.empty()) {
        int u = pq.top().second;
        //ll d = pq.top().first;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto &vw : adj[u]) {
            int v = vw[0];
            ll k = vw[1];
            if(dist[v] > dist[u] + k) {
                dist[v] = dist[u] + k;
                pq.push({dist[v],v});
            }
        }
    }

    for(int i = 1; i <= q; i++) {
        int u,v; cin>>u>>v;
        assert(u < v);
        ll ans = LLONG_MAX;
        if(v != n+1) {
            ans = min(ans, sum[v] - sum[u]);
            // go backward from u to 1, then 1 to n, then n to v
            ans = min(ans, sum[u] + sum[n+1] - sum[v]);
        }
        ans = min(ans, dist[u] + dist[v]);
        cout << ans << nl;
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

