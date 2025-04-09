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
const int LOG = 1 << 8;
void solve(){
        
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    int ans = 0;
    int now = 0;
    vector<bool> vis(LOG);
    vis[0] = true;
    for(auto &x : a) {
        now ^= x;
        for(int i = 0; i < (1 << 8); i++) {
            if(vis[i]) {
                ans = max(ans, now ^ i);
            }
        }
        vis[now] = true;
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

