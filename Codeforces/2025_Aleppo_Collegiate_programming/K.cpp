#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
void solve() {
    int n,x;
    cin>>n>>x;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    vector<bool> orr(n);
    int last = n, can = n - x;
    for(int i = 31; i >= 0; i--) {
        int cnt = 0, idx = -1;
        for(int j = last - 1; j >= 0; j--) {
            cnt++;
            if((1 << i) & a[j]) {
                idx = j; 
                break;
            }
        }

        if(idx != -1 && cnt <= can) {
            for(int j = idx; j < last; j++) {
                orr[j] = true;
            }
            last = idx;
            can -= cnt;
        }
    }
    int v = 0;
    for(int i = 0; i < n; i++) {
        if(orr[i]) {
            v |= a[i];
        } else {
            v &= a[i];
        }
    }
    cout << v;
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
