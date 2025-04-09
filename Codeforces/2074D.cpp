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

    vector<pl> a(n);
    for(auto &x : a) cin>>x.first;
    for(auto &x : a) cin>>x.second;
    sort(all(a));

    ll ans = 0;
    map<ll,ll> cnt;
    // O(n * ?) ???
    for(int i = 0; i < n; i++) {
        ll x = a[i].first, r = a[i].second;
        for(int j = x - r; j <= x + r; j++) {
            ll maxY = sqrtl(r * r - (j - x) * (j - x));
            cnt[j] = max(cnt[j], maxY);
        }
    }
    for(auto &x : cnt) {
        //cerr << x.first << nl;
        ans += 2ll * x.second + 1;
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

