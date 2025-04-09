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
    vector<int> a(m);
    for(auto &x : a) cin>>x;
    sort(all(a));
    ll ans = 0;
    for(int i = 0; i < m; i++) {
        ll k = n - a[i];
        ll cnt = m - (lower_bound(all(a), k) - a.begin());
        if(a[i] >= k) cnt--;
        cerr << k << " " << cnt << nl;
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

