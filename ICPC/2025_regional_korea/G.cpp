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
    ll x; cin>>n>>x;
    vector<ll> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin>>b[i];
    }

    auto f = [&](ll k) {
        // all value must >= k
        // with no more than x pressed button
        ll cur = 0;
        for(int i = 1; i <= n; i++) {
            if(a[i] >= k) continue;
            ll now = (k - a[i] + b[i] - 1) / b[i];
            cur += now;
        }
        return cur <= x;
    };

    ll l = 0, r = 2e18;
    while(l < r) {
        ll mid = l + (r - l + 1) / 2ll;
        if(f(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(a[i] > l) continue;
        ll now = (l - a[i]) / b[i] + 1;
        a[i] += now * b[i];
        x -= now;
    }
    for(int i = 1; i <= n && x > 0; i++) {
        if(a[i] == l+1) {
            a[i] += b[i];
            x--;
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

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

