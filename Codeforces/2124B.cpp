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
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    ll ans = 0, mn = n+1;
    for(int i = 0; i < n; i++) {
        mn = min(mn, a[i]);
        ans += mn;
    }
    ans = min(ans, a[0] + a[1]);
    if(n >= 3) {
        ans = min(ans, a[0] + a[2] + min(a[0]+a[2], a[1]));
        ans = min(ans, a[0] + min(a[0], a[1]+a[2]));
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

