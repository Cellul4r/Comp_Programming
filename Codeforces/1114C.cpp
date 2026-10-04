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
    
    ll n,b; cin>>n>>b;

    vector<array<ll,2>> factor;
    // get prime numbers of b
    ll tmp = b;
    for(ll i = 2; i * i <= tmp; i++) {
        ll cnt = 0;
        while(tmp % i == 0) {
            tmp /= i;
            cnt++;
        }
        if(cnt > 0) {
            factor.push_back({i,cnt});
        }
    }
    if(tmp > 1) {
        factor.push_back({tmp,1});
    }

    ll ans = LLONG_MAX;
    for(auto a : factor) {
        ll p = a[0], k = a[1];
        // p^k how many does prime p divide (1*2*3*4*5*...*n)?
        ll cur = p, cnt = 0;
        while(cur <= n) {
            cnt += n / cur; 
            // avoid overflow
            if(cur > n / p) break;
            cur *= p;
        }
        ans = min(ans, cnt / k);
    }
    cout << ans;
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

