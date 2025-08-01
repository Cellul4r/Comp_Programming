#include<bits/stdc++.h>
using namespace std;

#define all(a) a.begin(), a.end()
#define nl '\n'
typedef pair<int,int> pi;

const int N = 1e5+1;
const int INF = 1e9+7;
void solve() {
   
    int n,m;
    cin>>n>>m;
    vector<int> mnr(n+1, INF), mnc(m+1,INF), mxr(n+1), mxc(m+1);
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>a[i][j];
            mnr[i] = min(mnr[i], a[i][j]);
            mnc[j] = min(mnc[j], a[i][j]);
            mxr[i] = max(mxr[i], a[i][j]);
            mxc[j] = max(mxc[j], a[i][j]);
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int mn = min(mnr[i],mnc[j]);
            int mx = max(mxr[i],mxc[j]);
            if(mn == mx) {
                ans++;
            }
        }
    }
    cout << ans << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
