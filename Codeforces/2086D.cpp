/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =26;
const ll INF = 998244353;
const ll LINF = 1e18+7;

ll cnt[N+1];
ll fact[500001];
int n = 0;
/*ll dp[N][500001];
ll recur(int i, int cntEven) {
    if(i == N + 1) {
        if(cntEven == (n + 1) / 2) {
            return 1;
        }
        return 0;
    }
    if(cnt[i] == 0) {
        return recur(i+1, cntEven);
    }

    //if(~dp[i][cntEven]) return dp[i][cntEven];

    ll ans = 0;
    // choose left
    if(cntEven + cnt[i] <= (n + 1) / 2) {
        ans += recur(i + 1, cntEven + cnt[i]);
        ans %= INF;
    }
    // choose right
    if(cnt[i] <= n / 2) {
        ans += recur(i + 1, cntEven);
        ans %= INF;
    }

    return dp[i][cntEven] = ans;
}*/

ll powMod(ll x, ll y) {
    if(y == 0) return 1ll;
    ll t = powMod(x, y / 2ll);
    if(y & 1) {
        return (((x * t) % INF) * t) % INF;
    } else {
        return (t * t) % INF;
    }
}

void solve(){
    
    n = 0;
    for(int i = 1; i <= N; i++) {
        cin>>cnt[i];
        n += cnt[i];
    }

    ll ans = 1ll;
    ans *= fact[n / 2];
    ans %= INF;
    ans *= fact[(n+1) / 2];
    ans %= INF;
    ll deno = 1;
    for(int i = 1; i <= N; i++) {
        //cerr << cnt[i] << " ChHECK: " << fact[cnt[i]] << nl;
        deno *= fact[cnt[i]];
        deno %= INF;
    }
    //cerr << deno << nl;
    ans *= powMod(deno, INF - 2);
    ans %= INF;
    vector<vector<ll>> dp(N+1, vector<ll>(n+1,0));
    dp[0][0] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= n / 2; j++) {
            dp[i][j] = dp[i-1][j];
            if(j >= cnt[i] && cnt[i] != 0) {
                dp[i][j] += dp[i-1][j - cnt[i]];
                dp[i][j] %= INF;
            }
        }
    }
    //cerr << dp[N][n / 2];
    ans *= dp[N][n / 2];
    ans %=INF;
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    fact[0] = 1ll;
    for(int i = 1; i <= 500000; i++) {
        fact[i] = 1ll * i * fact[i-1];
        fact[i] %= INF;
    }
    cin>>t;
    while(t--)solve();

    return 0;
}


