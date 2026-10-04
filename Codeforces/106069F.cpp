/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;
using p = priority_queue<int, vector<int>, greater<>>;
void setIO(string);
void solve(){
    
    int n,m; cin>>n>>m;
    vector<array<int,3>> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    int b = sqrt(m);
    vector<vector<int>> vis(m+1);

    for(int i = 1; i <= n; i++) {
        if(a[i][0] > b) {
            // generate visit since contain <= sqrt(m) visit
            for(int j = a[i][1]; j <= m; j += a[i][0]) {
                vis[j].push_back(i);
            }
        }
    }

    vector<vector<int>> start(m+1);
    for(int i = 1; i <= n; i++) {
        if(a[i][0] <= b) {
            start[a[i][1]].push_back(i);
        }
    }

    vector<int> ans(n+1,-1);
    vector<vector<p>> pq(b+1);
    for(int i = 1; i <= b; i++) {
        pq[i].resize(i);
    }
    int cur = 1;
    for(int d = 1; d <= m; d++) {
        for(auto &i : start[d]) {
            pq[a[i][0]][a[i][1] % a[i][0]].push(i);
        }

        if(d < cur) continue;

        int now = INT_MAX;
        
        // small a in heap d % a, compatible b % a
        for(int i = 1; i <= b; i++) {
            while(!pq[i][d%i].empty() && ans[pq[i][d%i].top()] != -1) {
                pq[i][d%i].pop();
            }

            if(!pq[i][d%i].empty()) {
                now = min(now, pq[i][d%i].top());
            }
        }
        for(auto &i : vis[d]) {
            if(ans[i] == -1) {
                now = min(now, i);
            }
        }

        if(now != INT_MAX) {
            ans[now] = d;
            cur = d + a[now][2];
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
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

