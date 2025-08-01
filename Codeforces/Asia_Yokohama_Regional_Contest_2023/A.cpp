#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const string s = "YOKOHAMA";
const int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
int n,m;
string a[11];
ll recur(int i, int j, int k) {
    if(k == s.length()) {
        return 1;
    }
    
    ll ans = 0;
    for(int l = 0; l < 4; l++) {
        int ni = i + dr[l], nj = j + dc[l]; 
        if(ni < 0 || nj < 0 || ni >= n || nj >= m || a[ni][nj] != s[k]) continue;
        ans += recur(ni,nj, k+1);
    }

    return ans;
}
void solve() {
    
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] != 'Y') continue;
            ans += recur(i,j,1);
        }
    }
    cout << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
