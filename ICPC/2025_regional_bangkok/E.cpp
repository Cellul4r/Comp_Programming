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
    
    int n,m,q; cin>>n>>m>>q;
    ll dist[n+1][n+1];
    map<int,vector<array<ll,3>>> edges;

    for(int i = 0; i < m; i++) {
        int u,v,p;
        ll h; cin>>u>>v>>p>>h;
        edges[p].push_back({u,v,h});
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) {
                dist[i][j] = 0;
            } else {
                dist[i][j] = LINF;
            }
        }
    }

    vector<array<ll,2>> save[n+1]; 
    for(auto &[p, e] : edges) {
        // add edge to floyd-warshall in increasing order of pass level p
        for(auto &x : e) {
            int u = x[0] , v = x[1];
            ll h = x[2];
            dist[u][v] = min(dist[u][v], h);
        }

        // start process at pass level p
        for(auto &x : e) {
            int u = x[0] , v = x[1], h = x[2];
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][u] + dist[v][j] + h);
                }
            }
        }
        // end process at pass level p
        // find maximum distance from some u to v at this pass level == p
        for(int i = 1; i <= n; i++) {
            ll maxDist = 0;
            for(int j = 1; j <= n; j++) {
                maxDist = max(maxDist, dist[i][j]); 
            }
            // max dist from i to any city j with using pass level <= p
            save[i].push_back({p,maxDist});
        }
    }

    auto f = [&](int u, ll h) {
        int l = 0, r = save[u].size() - 1;
        int target = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            ll k = save[u][mid][1];
            if(k <= h) {
                target = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return target;
    };

    for(int i = 0; i < q; i++) {
        int op; cin>>op;
        if(op == 1) {
            int u; ll h; cin>>u>>h;
            int target = f(u,h);
            if(target == -1) {
                cout << -1;
            } else {
                cout << save[u][target][0];
            }
            cout << nl;
        } else {
            ll h; cin>>h;
            int minLevel = INF;
            int ans = -1;
            for(int u = 1; u <= n; u++) {
                int target = f(u,h); 
                if(target == -1) continue;
                //cerr << u << " CHECK: " << target << nl;
                if(save[u][target][0] < minLevel) {
                    minLevel = save[u][target][0];
                    ans = u;
                }
            }
            //cerr << "FUCK: " << ans << nl;
            if(minLevel == INF) minLevel = -1;
            cout << ans << " " << minLevel << nl;
        }
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

