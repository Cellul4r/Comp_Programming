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
const int N =2001;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n;
vector<pair<double,string>> ans;
void solve(){
    
    cin>>n;
    for(int i = 0; i < n; i++) {
        unordered_map<string,int> save;
        string ss; cin>>ss;
        int m; cin>>m;
        int cur = 0;
        vector<int> a(m), indeg(m);
        vector<vector<int>> adj(N);
        double x = 0, y = 0;
        for(int j = 0; j < m; j++) {
            int k;
            string s;
            cin>>s;
            if(save.find(s) == save.end()) {
                save[s] = cur++;
            }
            cin>>a[save[s]]>>k;
            x += a[save[s]];
            indeg[save[s]] += k;
            for(int l = 0; l < k; l++) {
                string t; cin>>t;
                if(save.find(t) == save.end()) {
                    save[t] = cur++;
                }
                adj[save[t]].push_back(save[s]);
            }
        }
        queue<int> Q;
        vector<int> dp(m);
        for(int j = 0; j < m; j++) {
            if(indeg[j] == 0) {
                Q.push(j);
                dp[j] = a[j];
            }
        }

        while(!Q.empty()) {
            int u = Q.front();
            y = max(y, (double)dp[u]);
            Q.pop();
            for(auto &v : adj[u]) {
                indeg[v]--;
                dp[v] = max(dp[v], dp[u] + a[v]);
                if(indeg[v] != 0) continue;
                Q.push(v);
            }
        }
        ans.push_back(make_pair(x / y, ss));
    }
    sort(all(ans));
    for(auto &[x,y] : ans) cout << y << nl;
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

