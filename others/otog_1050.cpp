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

int n,m,q;
int s,t;
vector<pi> adj[N];
ll dist1[N], dist2[N];
map<int,pair<int,pi>> save;
void solve(){
    
    cin>>n>>m>>q>>s>>t;
    for(int i = 0; i < n; i++) {
        dist1[i] = dist2[i] = LINF;
    }
    for(int i = 0; i < m; i++) {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
        save[i] = make_pair(u,make_pair(v,w));
    }

    auto f = [&](int s, ll dist[]) {
        priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> Q;
        vector<bool> vis(n);
        dist[s] = 0;
        Q.push(make_pair(dist[s],s));
        while(!Q.empty()) {
            int u = Q.top().second;
            Q.pop();
            if(vis[u]) continue;
            vis[u] = true;
            for(auto &vw : adj[u]) {
                auto v = vw.first, w = vw.second;
                if(!vis[v] && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    Q.push(make_pair(dist[v], v));
                }
            }
        }
    };
    f(s,dist1);
    f(t,dist2);
    for(int i = 0; i < q; i++) {
        int x;
        cin>>x;
        int u,v,w;
        u = save[x].first;
        v = save[x].second.first;
        w = save[x].second.second;
        //cerr << dist1[u] << nl;
        ll ans = min(dist1[u] + 1ll * w + dist2[v], dist1[v] + 1ll * w + dist2[u]);
        cout << ans << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

