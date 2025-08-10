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
typedef pair<pi, int> pii;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n,m;
vector<int> adj[N], rev[N];
int dist1[N], dist2[N];
// dist1 shortest path from node u to node 0 (can find in origin graph)
// dist2 the maximize minimum that troll can do
void solve(){

    cin>>n>>m;
    for(int i = 0; i < m; i++) {
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    
    memset(dist1, -1, sizeof dist1);
    queue<int> Q;
    dist1[0] = 0;
    Q.push(0);
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(auto &v : adj[u]) {
            if(dist1[v] == -1) {
                dist1[v] = dist1[u] + 1;
                Q.push(v);
            }
        }
    }

    memset(dist2, INF, sizeof dist2);
    dist2[n-1] = 0;
    for(auto &v : rev[n-1]) {
        dist2[v] = max(dist1[v], 1 + dist2[n-1]);
        Q.push(v);
    }

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for(auto &v : rev[u]) {
            if(dist2[v] > dist2[u] + 1) {
                dist2[v] = max(dist1[v], 1 + dist2[u]);
                Q.push(v);
            }
        }
    }
    for(int i = 0; i < n - 1; i++) {
        cout << dist2[i] << " ";
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

