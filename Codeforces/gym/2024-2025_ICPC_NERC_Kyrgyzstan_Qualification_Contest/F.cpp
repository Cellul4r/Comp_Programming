#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+1;
typedef long long ll;
int n;
ll a[N];
ll r[N], g[N], d[N];
ll ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    for(int i = 0; i < n; i++) {
        cin>>r[i]>>g[i]>>d[i];
    }

    for(int i = 0; i < n; i++) {
        ans += a[i];
        //cerr << "CHECK: " << ans << endl;
        ll k = (ans + d[i] + r[i] + g[i] - 1) * 1ll / (r[i] + g[i]);
        ll cur = -d[i] + k * (r[i] + g[i]);
        ll tmp = ans;
        ans = cur;
        if(k > 0) {
            cur = -d[i] + (k-1) * (r[i] + g[i]); 
            if(tmp >= cur && tmp < cur + g[i]) {
                ans = tmp; 
            }
        }
        //cout << ans << endl;
    }
    cout << ans;
    return 0;
}
