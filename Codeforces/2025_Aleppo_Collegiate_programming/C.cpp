#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> a(n), pre(n+1);
    for(auto &x : a) {
        cin>>x;
    }
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + a[i-1];
    }

    int ans = m;
    for(int i = 1; i <= m; i++) {
        bool ok = true;
        int j = 1;
        while(j <= n) {
            int k = upper_bound(pre.begin(), pre.end(), m - i + pre[j-1]) - pre.begin(); 
            if(k == n + 1) break;

            int s = pre[k] - pre[j-1];
            if(s > m) {
                ok = false;
                break;
            }
            j = k + 1; 
        }

        if(ok) {
            ans = i;
            break;
        }
    }
    cout << ans;
    cout << '\n';
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
