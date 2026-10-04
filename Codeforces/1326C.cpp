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
const ll LINF = 998244353;

void setIO(string);
ll sum(ll l, ll r) {
    // l + ... + r (l <= r)
    return r * (r + 1) / 2ll - (l-1) * l / 2ll;
}
void solve(){
    
    int n,k; cin>>n>>k;
    vector<int> a;
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        if(x >= n - k + 1) {
            a.push_back(i);
        }
    }
    sort(all(a));
    ll ans = 1;
    for(int i = 1; i < (int)a.size(); i++) {
        ans = ans * (a[i] - a[i-1]) % LINF;
    }
    cout << sum(n-k+1,n) << " " << ans;
    cout << nl;
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

