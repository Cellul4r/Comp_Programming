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

vector<int> adj[N];
void solve(){
    
    int n;
    cin>>n;
    for(int i = 0; i < n-1; i++) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, (int)adj[i].size() + 1);
    }

    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

