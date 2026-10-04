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
    
    int n,m; cin>>n>>m;
    ll d; cin>>d;
    
    vector<ll> a(n), b(m);
    for(auto &x : a) {
        cin>>x;
    }
    for(auto &x : b) {
        cin>>x;
    }
    sort(all(b));
    ll ans = -1;
    // a - b <= d
    // b >= a - d
    // b - a <= d
    // b <= a + d
    for(int i =0; i < n; i++) {
        auto it1 = lower_bound(all(b), a[i] - d);
        auto it2 = upper_bound(all(b), a[i] + d);

        if(it1 == b.end()) continue;
        int l = it1 - b.begin(), r = it2 - b.begin();
        //cerr << i << " " << l << " " << r << nl;
        if(l <= r-1) {
            ans = max(ans, a[i] + b[r-1]);
        }
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

