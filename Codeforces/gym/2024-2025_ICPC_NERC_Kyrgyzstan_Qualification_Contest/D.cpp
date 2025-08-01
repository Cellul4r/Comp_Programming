#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    sort(a.begin(), a.end());
    int ans = 0;
    for(int l = 0, r = 0; l < n;) {
        ans++;
        while(r + 1 < n && r + 1 - l + 1 <= k && a[r+1] - a[l] <= m) {
            r++;
        }
        l = r + 1;
    }
    cout << ans;
    return 0;
}
