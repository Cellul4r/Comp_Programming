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
    
    int n;
    cin>>n;
    vector<int> a(n);
    set<int> now;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        now.insert(a[i]);
    }
    sort(all(a));
    if(a[0] == a[n-1]) {
        cout << n / 2 << nl;
        return;
    }
    ll ans = 0;
    for(int l = 0, r = 0; l < n; l = ++r) {
        while(r+1 < n && a[r+1] == a[l]) r++;
        ans = max(ans, 1ll * (r + 1) * (n - r - 1));
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

