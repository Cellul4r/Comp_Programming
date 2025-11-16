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
    
    int n; cin>>n;
    vector<ll> a(n+1), pre(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
    }

    int q;
    cin>>q;

    auto f = [&](ll l, ll r) {
        if(l > r) return -LINF;
        ll sum = pre[r] - pre[l-1];
        return sum;
    };

    auto g = [&](ll u, ll k) {
        return k * u - k * (k-1) / 2ll;
    };

    for(int i = 0; i < q; i++) {
        ll l,u;
        cin>>l>>u;
        int lo = l-1, hi = n;
        while(lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if(f(l,mid) <= u) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        ll ans = lo;
        if(lo + 1 <= n && g(u,f(l,lo+1)) > g(u,f(l,ans))) {
            ans = lo + 1;
        }
        if(lo - 1 >= l && g(u,f(l,lo-1)) >= g(u,f(l,ans))) {
            ans = lo - 1;
        }
        cout << max(l, ans) << " ";
    }
    cout << nl;
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

