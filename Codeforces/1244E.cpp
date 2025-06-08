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
    
    int n;
    ll k;
    cin>>n>>k;
    vector<int> a(n);
    vector<ll> pre(n+1);
    for(auto &x : a) cin>>x;
    sort(all(a));
    for(int i = 1; i <= n; i++) pre[i] += 1ll * a[i-1] + pre[i-1];

    auto f = [&](int x) {
        // let L = l
        for(int l = 0; l < n; l++) {
            int r = upper_bound(all(a), a[l] + x) - a.begin();
            ll steps = 1ll * a[l] * l - pre[l] + pre[n] - pre[r] - 1ll * (a[l] + x) * (n - r);
            if(steps <= k) return true;
        }
        for(int r = 0; r < n; r++) {
            int l = lower_bound(all(a), a[r] - x) - a.begin();
            ll steps = 1ll * (a[r] - x) * l - pre[l] + pre[n] - pre[r] - 1ll * a[r] * (n - r);
            if(steps <= k) return true;
        }
        return false;
    };
    int l = 0, r = 1e9+5;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(f(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
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

