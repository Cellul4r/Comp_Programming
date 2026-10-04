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
void solve(){

    int n,m;
    cin>>n>>m;
    vector<vector<pi>> a(n);
    vector<int> ans(m, -1), day1(n, 0), day2(n,0), cnt(n,0);
    for(int i = 0; i < m; i++) {
        int x,y;
        cin>>x>>y;
        x--,y--;
        a[x].push_back({y,i});
        a[y].push_back({x,i});
        cnt[x]++;
        cnt[y]++;
    }

    vector<bool> vis(n,false);
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
                return cnt[i] > cnt[j];
            });

    for(auto &x : ord) {
        if(vis[x]) continue;
        queue<int> Q;
        Q.push(x);
        vis[x] = true;
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();        
            for(auto &vi : a[u]) {
                int v = vi.first, i = vi.second;
                if(ans[i] == -1) {
                    if(day1[u] <= day2[u]) {
                        day1[u]++;
                        day1[v]++;
                        ans[i] = 1;
                    } else {
                        day2[u]++;
                        day2[v]++;
                        ans[i] = 2;
                    }
                }
                if(!vis[v]) {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
    }

    ll now = 0;
    for(int i = 0; i < n; i++) {
        now += 1ll * day1[i] * day1[i] + 1ll * day2[i] * day2[i];
    }

    cout << now << " ";
    for(auto &x : ans) {
        cout << x;
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    for(int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

