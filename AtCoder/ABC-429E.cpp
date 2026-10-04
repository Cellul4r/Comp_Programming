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
const int N =2e5+5;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
struct p {

    ll val[2];
    int k[2];
};
vector<int> adj[N];
p level[N];
bool vis[N][2];
void solve(){

    int n,m;
    string s;
    cin>>n>>m;
    memset(vis, false, sizeof vis);
    for(int i = 1; i <= m; i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin>>s;
    for(int i = 1; i <= n; i++) {
        level[i].val[0] = -1;
        level[i].val[1] = LINF;
        level[i].k[0] = level[i].k[1] = -1;
    }

    queue<array<int,2>> Q;
    for(int i = 1; i <= n; i++) {
        if(s[i-1] == 'S') {
            Q.push({i,0});
            level[i].val[0] = 0;
            level[i].k[0] = i;
        }
    }

    while(!Q.empty()) {
        int u = Q.front()[0], now = Q.front()[1];
        //cerr << u << nl << nl;
        Q.pop();
        vis[u][now] = true;
        for(auto &v : adj[u]) {
            if(level[v].val[0] == -1) {
                level[v].val[0] = level[u].val[now] + 1;
                level[v].k[0] = level[u].k[now];
                Q.push({v,0});
            } else if(!vis[v][0] && level[v].val[0] > level[u].val[now] + 1 && level[v].k[0] != level[u].k[now]) {
                level[v].val[1] = level[v].val[0];
                level[v].k[1] = level[v].k[0];
                level[v].val[0] = level[u].val[now] + 1;
                level[v].k[0] = level[u].k[now];
                Q.push({v,0});
            } else if(!vis[v][1] && level[v].val[1] > level[u].val[now] + 1 && level[v].k[0] != level[u].k[now]) {
                level[v].val[1] = level[u].val[now] + 1;
                level[v].k[1] = level[u].k[now];
                Q.push({v,1});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(s[i-1] == 'S') continue;
        //cout << level[i][0] << nl;
        //cout << level[i].k[0] << " " << level[i].k[1] << nl;
        cout << level[i].val[0] + level[i].val[1] << nl;
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

