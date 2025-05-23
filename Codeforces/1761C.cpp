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
const int N =100+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n;
vector<int> ans[N];
vector<int> adj[N];
bool used[N];
void dfs(int u) {
    
    if(!ans[u].empty()) return;
    //cerr << u << endl;
    for(auto &v : adj[u]) {
        dfs(v);
        for(auto &k : ans[v]) {
            if(find(all(ans[u]), k) == ans[u].end()) ans[u].push_back(k);
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!used[i]) {
            used[i] = true;
            ans[u].push_back(i);
            return;
        }
    }
}

void solve(){
    
    cin>>n;
    vector<vector<int>> board(n+1, vector<int>(n+1));
    vector<int> indeg(n+1);
    for(int i = 1; i <= n; i++) {
        ans[i].clear();
        adj[i].clear();
        used[i] = false;
    }
    for(int i = 1; i <= n; i++) {
        string s;
        cin>>s;
        for(int j = 1; j <= n; j++) {
            board[i][j] = s[j - 1] - '0';
            if(board[i][j]) {
                adj[j].push_back(i);
                indeg[i]++;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) {
            dfs(i);
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i].size() << " ";
        for(auto &v : ans[i]) {
            cout << v << " ";
        }
        cout << nl;
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

