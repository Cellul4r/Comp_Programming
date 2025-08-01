#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    cout << a[0] << " ";
    for(int i = 1; i < n; i++) {
        if(i + 2 < n && a[i+1] < a[i]) {
            cout << a[i+1] << " ";
            cout << a[i] << " ";
            cout << a[i+2] << " ";
            i += 2;
        } else {
            cout << a[i] << " ";
        }
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
