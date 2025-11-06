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
    vector<ll> a(n+1);
    a[0] = LINF;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    ll mx = 1;
    for(int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
        if(i % 2 == 0) {
            a[i] = mx;
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; i += 2) {
        ll k = 0;
        if(a[i] >= a[i-1]) {
            k = max(k, a[i] - a[i-1] + 1);
        }
        if(i+1 <= n && a[i] >= a[i+1]) {
            k = max(k, a[i] - a[i+1] + 1);
        }
        ans += k;
    }

    cout << ans << nl;
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

