#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,q;
map<pi,int> a;
void solve() {
    
    cin>>n>>q;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if((i + j) % 2 == 0) {
                a[make_pair(i,j)] = 1;
            } else {
                a[make_pair(i,j)] = 0;
            }
        }
    }

    ll ans = 1ll * n * n;
    for(int k = 1; k <= q; k++) {
        string op;
        int i;
        cin>>op>>i;
        if(op == "ROW") {
             
        } else {

        }
    }
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
