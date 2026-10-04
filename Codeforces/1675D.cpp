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
vector<vector<int>> ans;
void dfs(int u, int p, vector<vector<int>>& adj, vector<int>& now) {

    now.push_back(u);
    if(adj[u].size() == 0) {
        ans.push_back(now);
        return;
    }
    for(auto &v : adj[u]) {
        if(v == p) continue; 
        dfs(v, u, adj, now);
        now.clear();
    }
}
void solve(){
    
    int n;
    cin>>n;
    vector<vector<int>> a(n+1);
    int cur = -1;
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        if(i == x) {
            cur = i;
            continue;
        }
        a[x].push_back(i);
    }

    ans.clear();
    vector<int> now;
    dfs(cur, -1, a, now);
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x.size() << nl;
        for(auto &y : x) {
            cout << y << " ";
        }
        cout << nl;
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

