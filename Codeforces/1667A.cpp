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
    vector<ll> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    ll ans = LINF;
    for(int i = 0; i < n; i++) {
        // this index do no operation.
        // then from j to i - 1
        // we need to do operation minus a[i]
        ll prev_ = 0;
        ll op = 0;
        for(int j = i - 1; j >= 0; j--) {
            prev_ += a[j] - prev_ % a[j];
            op += prev_ / a[j];
        }
        prev_ = 0;
        for(int j = i + 1; j < n; j++) {
            prev_ += a[j] - prev_ % a[j];
            op += prev_ / a[j];
        }
        ans = min(ans, op);
    }

    cout << ans << nl;
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

