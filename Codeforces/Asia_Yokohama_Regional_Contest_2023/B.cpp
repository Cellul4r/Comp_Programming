#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,c,p,q;
double now;
int ans = 0;
string s;
int pre[500001];
int rnk[500001];
void solve() {
    
    cin>>n>>c>>p>>q;
    now = (double)p / (double)q;
    cin>>s;
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + (s[i-1] == 'Y' ? 1 : 0);
    }
    for(int i = 1; i <= n; i++) {
        bool found = false;
        rnk[i] = ans;
        for(int s = 1; s <= i - c + 1; s++) {
            if(ans != rnk[s]) continue;
            double check = (double)(pre[i] - pre[s-1]) / (double)(i-s+1);
            if(check >= now) {
                found = true;
                break;
            }
        }
        if(found) {
            //cout << i << endl;
            ans++;
        }
    }
    cout << ans;
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
