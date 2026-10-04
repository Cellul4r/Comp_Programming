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
const int N =1e4+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
vector<array<int,3>> adj[N];
double dist[N];
bool vis[N];
int n,m,t;
void solve(){

    memset(vis, false, sizeof vis);

    cin>>n>>m>>t;
    for(int i = 0; i < n; i++) {
        dist[i] = 1e9;
    }
    for(int i = 0; i < m; i++) {
        int a,b,l,v;
        cin>>a>>b>>l>>v; a--, b--;
        adj[a].push_back({b,l,v});
        adj[b].push_back({a,l,v});
    }

    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
    dist[0] = 0;
    pq.push(make_pair(dist[0],0));
    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u] = true;

        for(auto &vw : adj[u]) {
            if(dist[vw[0]] > dist[u] + (1.00 * vw[1] / vw[2])) {
                dist[vw[0]] = dist[u] + (1.00 * vw[1] / vw[2]);
                pq.push(make_pair(dist[vw[0]], vw[0]));
            }
        }
    }

    if(dist[n-1] <= t) {
        cout << 0;
        return;
    }

    double l = 0, r = 1e9;
    int it = 0;
    while(it++ < 200) {
        double mid = (l + r) / 2.00;
        memset(vis, false, sizeof vis);
        for(int i = 0; i < n; i++) {
            dist[i] = 1e9;
        }
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
        dist[0] = 0;
        pq.push(make_pair(dist[0],0));
        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();
            if(vis[u]) continue;
            vis[u] = true;

            for(auto &vw : adj[u]) {
                if(dist[vw[0]] > dist[u] + (1.00 * vw[1] / ((double)vw[2] + mid))) {
                    dist[vw[0]] = dist[u] + (1.00 * vw[1] / ((double)vw[2] + mid));
                    pq.push(make_pair(dist[vw[0]], vw[0]));
                }
            }
        }
        if(dist[n-1] > t) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(10) << r;
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

