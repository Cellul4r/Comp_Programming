#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
        
    int n;
    cin>>n;
    vector<int> a(n), b;
    int min_ = INT_MAX;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        min_ = min(min_, a[i]);
    }
    b = a;
    sort(b.begin(),b.end());
    
    int k = 0;
    for(int i=0;i<n;i++) {
        if(a[i] != b[i] && a[i] % min_ != 0) {
            k = 1;
        }
    }
    if(!k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    // 4 3 6 6 2 9
    // 2 3 4 6 6 9
    // swap(4,2) ?
    // 2 3 6 6 4 9
    // 2 3 4 2
    // 7 5 2 2 4
    // 
    // swap)
}
int main() {
	// your code goes here
    int t=1;
    cin>>t;
    while(t--) {
        solve();
    }
}
