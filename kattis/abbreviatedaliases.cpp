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
    
    int n,m; cin>>n>>m;
    map<string,int> cnt;
    vector<string> b(n), a(n);
    vector<bool> vis(n);
    int ans = 0;
    for(auto &x : a) cin>>x;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[j]) {
                b[j] += a[j][i];
                cnt[b[j]]++;
            }
        }

        for(int j = 0; j < n; j++) {
            if(vis[j]) continue;
            if(cnt[b[j]] == 1) {
                vis[j] = true;
                ans += i+1;
            }
        }
        cnt.clear();
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

