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
vector<pi> adj[N];
ll dist[N];
void solve(){
    
    int n,m,s,t,c; cin>>n>>m>>s>>t>>c;
    for(int i = 0; i < m; i++) {
        int u,v,p;
        cin>>u>>v>>p;
        adj[u].push_back(make_pair(v,p));
        adj[v].push_back(make_pair(u,p));
    }

    queue<int> Q;
    Q.push(s);
    dist[s] = c;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        //cerr << u << " " << dist[u] << nl;
        for(auto &vp : adj[u]) {
            int v = vp.first, p = vp.second;
            int k = ((100 - p) * dist[u]) / 100;
            if(dist[v] < k) {
                dist[v] = k;
                Q.push(v);
            }
        }
    }
    cout << dist[t];
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

