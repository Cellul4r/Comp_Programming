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
    cin>>n;
    vector<long double> a(n);
    vector<long long> cur(n);
    long double mx = 0, mn = 1;
    for(auto &x : a) {
        cin>>x;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    for(long long i = 1; i <= 10000; i++) {
        // let r[0] = i
        // from a[i] = r[i] / d
        // d = r[i] / a[i] and r[i] = a[i] * d
        long double d = 1.00 * i / mx;
        for(int j = 0; j < n; j++) {
            cur[j] = roundl(a[j] * d);
            if(a[j] == mx) cur[j] = i;
        }

        bool ok = true;
        long long now = 0;
        for(auto &x : cur) {
            if(x <= 0 || x > 10000) ok = false;
            now = gcd(now, x);
        }
        if(now != 1) continue;
        d = 0;
        for(auto &x : cur) {
            d += 1.00 * x * x;
        }

        d = sqrtl(d);
        for(int j = 0; j < n; j++) {
            long double k = 1.00 * cur[j] / d;
            if(fabsl(a[j] - k) > 1e-6) {
                ok = false;
            }
        }

        if(ok) {
            for(auto &x : cur) {
                cout << x << nl;
            }
            return;
        }

        d = 1.00 * i / mn;
        for(int j = 0; j < n; j++) {
            cur[j] = roundl(a[j] * d);
            if(a[j] == mn) cur[j] = i;
        }

        ok = true;
        now = 0;
        for(auto &x : cur) {
            if(x <= 0 || x > 10000) ok = false;
            now = gcd(now, x);
        }
        if(now != 1) continue;
        d = 0;
        for(auto &x : cur) {
            d += 1.00 * x * x;
        }

        d = sqrtl(d);
        for(int j = 0; j < n; j++) {
            long double k = 1.00 * cur[j] / d;
            if(fabsl(a[j] - k) > 1e-6) {
                ok = false;
            }
        }

        if(ok) {
            for(auto &x : cur) {
                cout << x << nl;
            }
            return;
        }
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

