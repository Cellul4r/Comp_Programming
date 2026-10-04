/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n; cin>>n;
    map<int,int> cnt;
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        cnt[x]++;
    }
    ll ans = 0;
    for(auto it = cnt.rbegin(); it != cnt.rend(); ++it) {
        auto &[x,y] = *it;
        ans += 1ll * y / 2ll;
        if(y % 2 == 1 && cnt[x-1] > 0) {
            cnt[x-1]--;
            ans++;
        }
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

