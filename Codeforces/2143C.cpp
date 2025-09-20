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

void setIO(string);
vector<int> adj[N];
int val[N];
int par[N];
int deg[N];
map<pi,pi> save;
void dfs(int u, int p) {
    par[u] = p;
    for(auto &v : adj[u]) {
        if(v == p) continue;
        dfs(v,u);
    }
}
void solve(){
    
    int n; cin>>n;
    for(int i = 0; i < n; i++) {
        adj[i].clear();
        par[i] = -1;
        deg[i] = 0;
        val[i] = -1;
    }
    for(int i = 0; i < n - 1; i++) {
        ll u,v,x,y;
        cin>>u>>v>>x>>y;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
        save[make_pair(u,v)] = make_pair(x,y);
        save[make_pair(v,u)] = make_pair(x,y);
    }

    int root = 0;
    dfs(root,-1);
    for(int i = 0; i < n; i++) {
        if(i == root) continue;
        deg[i]--;
        int v = par[i];
        int x = save[make_pair(i,par[i])].first;
        int y = save[make_pair(i,par[i])].second;
        //cerr << i << " " << par[i] << " " << x << " " << y << nl;
        if(x < y) {
            val[i] = 0;
        } else {
            val[i] = 1;
        }
        if(v > i) val[i] = !val[i];
    }
    queue<int> Q;
    for(int i = 0; i < n; i++) {
        if(deg[i] == 0) Q.push(i);
    }
    vector<int> ans(n);
    deque<int> now;
    for(int i = 0; i < n; i++) now.push_back(i);
    while(!Q.empty()) {
        int u = Q.front();
        //cerr << u << nl;
        Q.pop();
        if(val[u] == 0) {
            ans[u] = now.back();
            now.pop_back();
        } else {
            ans[u] = now.front();
            now.pop_front();
        }
        for(auto &v : adj[u]) {
            deg[v]--;
            if(deg[v] == 0) {
                Q.push(v);
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }
    cout << nl;
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

