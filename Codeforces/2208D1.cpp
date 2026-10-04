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
const int N =501;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int a[N][N], b[N][N];
vector<array<int,2>> ans;
int n;
void solve(){
    
    cin>>n;
    assert(n <= 500);
    ans.clear();
    for(int i = 1; i <= n; i++) {
        string s; cin>>s;
        for(int j = 1; j <= n; j++) {
            a[i][j] = (s[j-1] - '0');
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            if(a[i][j] == 1 && a[j][i] == 1) {
                cout << "NO\n";
                return;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j || a[i][j] == 0) continue;
            bool flag = true;
            for(int k = 1; k <= n; k++) {
                if(k == i || k == j) continue;
                if(a[i][k] == 1 && a[k][j] == 1) {
                    flag = false;
                }
            }
            if(flag) {
                ans.push_back({i,j});
            }
        }
    }

    if((int)ans.size() != n - 1) {
        cout << "NO\n";
        return;
    }

    vector<vector<int>> di(n+1);
    for(auto &x : ans) {
        di[x[0]].push_back(x[1]);
        di[x[1]].push_back(x[0]);
    }
    vector<bool> vis(n+1);
    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    int cnt = 0;
    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        cnt++;
        for(auto &v : di[u]) {
            if(vis[v]) continue;
            vis[v] = true;
            Q.push(v);
        }
    }
    if(cnt != n) {
        cout << "NO\n";
        return;
    }
    vector<vector<int>> adj(n+1);
    for(auto &x : ans) {
        adj[x[0]].push_back(x[1]);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            b[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i++) {
        b[i][i] = 1;
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for(auto &v : adj[u]) {
                if(b[i][v] == 0) {
                    b[i][v] = 1;
                    Q.push(v);
                }
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j] != b[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    for(auto &x : ans) {
        cout << x[0] << " " << x[1] << nl;
    }
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

