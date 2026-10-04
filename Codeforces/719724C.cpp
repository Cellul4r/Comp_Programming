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
    
    // no edge between odd vertices
    // edge between power of 2^i can go by 1 edge
    // s == t -> return 0
    // if s or t is equal to 2^lg - 1
    ll n,q; cin>>n>>q;
    int lg = 0;
    while((1ll<<lg) <= n) lg++;
    for(int i = 1; i <= q; i++) {
        ll u,v; cin>>u>>v;
        if(u == v) {
            cout << 0 << nl;
            continue;
        }
        if((u&v) == 0) {
            cout << u + v << nl;
            continue;
        }
        vector<ll> dp(lg, LLONG_MAX);
        if(__builtin_popcount(u) == 1) {
            for(int k = 0; k < lg; k++) {
                if((1ll<<k)&u) {
                    dp[k] = 0;
                    break;
                }
            }
        }
        for(int k = 0; k < lg; k++) {
            if((1ll << k) & u) continue;
            dp[k] = u + (1ll << k);
        }
        vector<bool> vis(lg, false);
        while(true) {
            bool found = false;
            for(int k = 0; k < lg; k++) {
                if(vis[k]) continue;
                if(dp[k] == LLONG_MAX) {
                    continue;
                }
                //cout << "WOW: " << k << nl;
                for(int l = 0; l < lg; l++) {
                    if(l == k) continue;
                    if(dp[l] > dp[k] + (1ll << k) + (1ll << l)) {
                        //cout << "UP: " << l << " : " << dp[k] << nl;
                        dp[l] = dp[k] + (1ll << k) + (1ll << l);
                        vis[l] = false;
                    }
                }
                found = true;
                vis[k] = true;
            }
            if(!found) break;
        }
        ll ans = LLONG_MAX;
        if(__builtin_popcount(v) == 1) {
            for(int k = 0; k < lg; k++) {
                if((1ll<<k)&v) {
                    ans = dp[k];
                    break;
                }
            }
        } else {
            for(int k = 0; k < lg; k++) {
                if((1ll<<k) & v) continue;
                if(dp[k] == LLONG_MAX) continue;
                //cout << k << " " << dp[k] << nl;
                ans = min(ans, dp[k] + (1ll << k) + v);
            }
        }
        /*
        if(u == (1ll<<lg) - 1 || v == (1ll<<lg) - 1) {
            cout << -1 << nl;
            return;
        }
        */
        if(ans == LLONG_MAX) ans = -1;
        cout << ans << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

