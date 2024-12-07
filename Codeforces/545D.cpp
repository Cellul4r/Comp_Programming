#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
        
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int cnt = 0;
    ll now = 0;
    for(int i=0;i<n;i++) {
        if(now > a[i]) {
            cnt++;
            continue;
        }
        now += a[i];
    }
    cout << n - cnt;
}
int main() {
	// your code goes here
    int t=1;
    // cin>>t;
    while(t--) {
        solve();
    }
}
