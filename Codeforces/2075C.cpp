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
    
    int n,m;
    cin>>n>>m;
    vector<ll> a(m);
    for(auto &x : a) cin>>x;
    sort(all(a));
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        ll l = (lower_bound(all(a), i) - a.begin());
        ll k = n - i;            
        ll r = (lower_bound(all(a), k) - a.begin());
        ll left = m - l, right = m - r;
        if(left == 0 || right == 0) continue;
        if(left > right) {
            ans += (left - 1ll) * right;
        } else {
            ans += left * (right - 1ll);
        }
        //cerr << i << " WITH: " << k << " -> " << " POS: " << l << " " << r << " -> " << left << " " << right << nl;
    }

    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

