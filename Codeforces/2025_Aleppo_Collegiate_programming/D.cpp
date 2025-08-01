#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
void solve() {
    int n;
    cin>>n;
    vector<bool> vis(n);
    vector<pi> ans;
    vector<string> a(n);
    vector<int> cnt(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        for(int j = 0; j < n; j++) {
            if(a[i][j] != '0' && j != 0) {
                cnt[i]++;
            }
        }
    }
    vis[0] = true;
    for(int i = 0, run = 0; run < n - 1; run++) {
        int idx = -1, mx = -1;
        //cout << i << endl;
        for(int j = 0; j < n; j++) {
            if(vis[j] || i == j) continue;
            if(a[i][j] == '1' || a[i][j] == '?') {
                if(mx < cnt[j]) {
                    mx = cnt[j];
                    idx = j;
                }
            }
        }
        //cout << idx << endl;
        if(idx == -1) break;
        ans.push_back(make_pair(i,idx));
        vis[idx] = true;
        for(int j = 0; j < n; j++) {
            if(idx == j) continue;
            if(a[j][idx] == '1' || a[j][idx] == '?') {
                a[j][idx] = '0';
                cnt[j]--; 
            }
        }
        /*if(idx == 3) {
            cout << cnt[idx] << endl;
        }*/
        if(true) {
            i = idx;
        }
    }
    if(ans.size() == n - 1) {
        reverse(ans.begin(), ans.end());
        cout << "Yes\n";
        for(auto &[x,y] : ans) {
            cout << x + 1 << " " << y + 1 << '\n';
        }
    } else {
        cout << "No\n";
    }

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
