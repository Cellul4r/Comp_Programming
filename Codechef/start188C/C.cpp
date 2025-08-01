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
    vector<ll> a(n);
    for(auto &x : a) cin>>x;
    sort(all(a));
    ll ans = n;
    ll now = 0;
    for(int i = 0; i < n; i++) {
        ans = min(ans, a[i] + n - i - 1);
    }
    for(int i = 0; i < n-1; i++) {
        a[i] -= now;
        a[i] = max(0ll,a[i]);
        now += a[i];
    }
    a[n-1] -= now;
    if(a[n-1] > 0) now++;
    cout << min(now,ans) << nl;
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

