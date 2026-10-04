/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int lpf[N];
void init() {
    lpf[0] = 0;
    lpf[1] = 1;

    for(ll i = 2; i < N; i++) {
        bool found = false;
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) {
                lpf[i] = j;
                found = true;

                break;
            }
        }
        if(!found) {
            lpf[i] = i;
        }
    }
}
void solve(){
    
    // each a[i] is independent since the operation can change only 1 element at a time
    int n,k; cin>>n>>k;
    // dp? minimum number of operations to make number i <= k
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    vector<ll> dp(n+1, LLONG_MAX);
    for(int i = 0; i <= k; i++) {
        dp[i] = 0;
    }
    for(int i = k + 1; i <= n; i++) {
        // find prime number composition of this number i
        int tmp = i;
        while(tmp > 1) {
            int x = lpf[tmp];
            dp[i] = min(dp[i], 1ll + 1ll * dp[i / x] * x);

            while(tmp % x == 0) {
                tmp /= x;
            }
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += dp[a[i]];
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    init();
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

