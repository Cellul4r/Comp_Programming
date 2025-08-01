#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;
int n;
void solve() {
    
    int x,y;
    cin>>x>>y;
    cout << max({abs(x),abs(y),abs(x+y)}) << endl;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
