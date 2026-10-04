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
int n;
vector<pi> adj[N];
int a[N];
void dfs(int u, int p) {

    for(auto &vw : adj[u]) {
        int v = vw.first, w = vw.second;
        if(v == p) continue;
        a[v] = w ^ a[u]; 
        dfs(v,u);
    }
}
void solve(){

   cin>>n;
   for(int i = 0; i < n - 1; i++) {
       int u,v,w; cin>>u>>v>>w;
       adj[u].push_back({v,w});
       adj[v].push_back({u,w});
   }
   dfs(1,0);

   ll ans = 0;
   for(int i = 0; i < 26; i++) {
       ll cnt = 0;
       for(int j = 1; j <= n; j++) {
           if((1<<i) & a[j]) {
                cnt++;   
           }
       }
       ans += cnt * (n - cnt) * (1ll << i);
   }
   cout << ans;
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

