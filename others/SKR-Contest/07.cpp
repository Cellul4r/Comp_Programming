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
const int N =2001+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

vector<int> adj[N];
ll a[N],b[N];
void solve(){
    
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>> b[i];
    for(int i=0;i<n;i++) cin>> a[i];
    for(int i=0;i<m;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<ll> dist(n,LINF);
    vector<bool> vis(n);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> Q;
    dist[0] = 0;
    Q.push(make_pair(dist[0],0));
    while(!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        vis[u] = true;
        for(auto &v : adj[u]) {
            if(!vis[v] && dist[v] > a[u] + b[v] + dist[u]) {
                dist[v] = dist[u] + a[u] + b[v];
                Q.push(make_pair(dist[v], v));
            }
        }
    }
    for(auto &x : dist) {
        cout << (x == LINF ? -1 : x) << " ";
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

