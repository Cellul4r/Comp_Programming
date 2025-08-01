#include<bits/stdc++.h>
using namespace std;

const int N = 35;
typedef long long ll;
int n,k;
int r[N];
ll ans[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(int i = 0; i < k; i++) {
        int x;
        cin>>x;
        x--;
        r[x] = 1;
    }
    ans[0] = 1;
    for(int i = 1; i <= n; i++) {
        if(r[i-1]) {
            ans[i] = 2ll * ans[i-1] + 1ll; 
        } else {
            ans[i] = ans[i-1] + 1;
        }
    }
    cout << ans[n] - 1;
    return 0;
}
