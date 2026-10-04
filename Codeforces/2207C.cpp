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
    
    int n,h; cin>>n>>h; 
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        // amount of water
        a[i] = h - a[i];
    }

    vector<ll> cnt(n+1, 0ll);
    vector<vector<int>> mn(n+1, vector<int>(n+1, 0ll));
    for(int i = 1; i <= n; i++) {
        // left
        mn[i][i] = i;
        cnt[i] += a[i];
        for(int j = i - 1, cur = a[i]; j >= 1; j--) {
            cur = min(1ll * cur, a[j]);
            cnt[i] += 1ll * cur;
        }
        // right
        for(int j = i + 1, cur = a[i]; j <= n; j++) {
            if(a[mn[i][j-1]] > a[j]) {
                mn[i][j] = j; 
            } else {
                mn[i][j] = mn[i][j-1];
            }
            cur = min(1ll * cur, a[j]);
            cnt[i] += 1ll * cur;
            //cout << i << " " << j << ": " << mn[i][j] << nl;
        }
    }
    // how to find min in range[i,j] in O(n^2)?
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            ans = max(ans, cnt[i] + cnt[j] - cnt[mn[i][j]]);
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

