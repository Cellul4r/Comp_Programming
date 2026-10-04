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

void setIO(string);
void test() {
    for(int i = 0; i < 16; i++) {
        cout << "TEST: " << i << nl;
        for(int mask = 0; mask < (1 << 5); mask++) {
            int cur = i;
            for(int j = 0; j < 5; j++) {
                if(mask & (1<<j)) {
                    cur = cur xor ((j+1) * 3);
                }
            }
            cout << cur << " ";
        }
        cout << nl;
    }
}
bool vis[16];
void init() {
    memset(vis, false, sizeof vis);
    vis[0] = vis[3] = vis[5] = vis[6] = vis[9] = vis[10] = vis[12] = vis[15] = true;
}
void solve(){
    //test();
    int n,q; cin>>n>>q;
    int ans = 0;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        if(vis[a[i]]) {
            ans++;
        }
    }
    cout << ans << " ";
    for(int i = 1; i <= q; i++) {
        int idx,x; cin>>idx>>x;
        if(vis[a[idx]]) {
            ans--;
        }
        a[idx] = x;
        if(vis[a[idx]]) {
            ans++;
        }
        cout << ans << " ";
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    init();
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

