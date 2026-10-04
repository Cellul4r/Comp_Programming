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
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    ll n,h,k; cin>>n>>h>>k;
    vector<ll> a(n+1), pre(n+1), suff(n+2);
    ll sum = 0;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        sum += a[i];
    }
    pre[1] = a[1];
    for(int i = 2; i <= n; i++) {
        pre[i] = min(pre[i-1], a[i]);
    }
    suff[n] = a[n];
    for(int i = n - 1; i >= 1; i--) {
        suff[i] = max(suff[i+1], a[i]);
    }
    ll use = h / sum;
    ll ans = 0;
    h -= use * sum;
    ans += use * n;
    // reload ammo
    if(h == 0) {
        if(use > 0) ans += k * (use - 1);
    } else {
        ans += k * use;
        ll cur = 0;
        for(int i = 1; i <= n; i++) {
            cur += a[i];
            // swap a[i] and a[j] with min and max value
            if(cur - pre[i] + suff[i+1] >= h || cur >= h) {
                ans += i;
                break;
            }
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

