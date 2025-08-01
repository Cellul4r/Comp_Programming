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

void solve(){
    
    ll n,k;
    cin>>n>>k;
    ll ans = 0, now = 0;
    ll prev_ = -1;
    for(int i = 0; i < n; i++) {
        ll x;
        cin>>x;
        if(prev_ == -1) {
            now = k + 1;
            prev_ = x;
            continue;
        }
        if(x - prev_ <= k) {
            now += x - prev_;
        } else {
            ans += now;
            now = k + 1;
        }
        prev_ = x;
    }
    ans += now;
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

