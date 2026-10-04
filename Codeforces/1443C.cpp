/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n; cin>>n;
    vector<array<int,2>> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i][0];
    }
    for(int i = 0; i < n; i++) {
        cin>>a[i][1];
    }

    ll sum = 0;
    ll ans = LINF;
    sort(all(a));
    for(int i = n - 1; i >= 0; i--) {
        ans = min(ans, max(sum, 1ll * a[i][0]));
        sum += a[i][1];
    }
    ans = min(ans, sum);
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

