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
const int N =1e6+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
vector<int> adj[N];
int par[N];
void count(int u, int p, int& leaves) {
    if(adj[u].size() == 0) {
        leaves++;
        return;
    }

    for(auto &v : adj[u]) {
        if(v == p) continue;
        count(v, u, leaves);
    }
}
void solve(){
    
    int n,k;
    cin>>n>>k;
    memset(par, 0, sizeof par);
    for(int i = 1; i < n; i++) {
        int u;
        cin>>u;
        adj[u].push_back(i);
        par[i] = u;
    }
    int leaves = 0;
    count(0,0,leaves);
    //cout << leaves;
    if(k == n - 1) {
        cout << 1;
        return;
    }
    int ans;
    if(leaves >= k) {
        ans = leaves-k;
    } else {
        ans = 0;
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

