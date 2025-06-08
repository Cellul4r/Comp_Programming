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
    vector<int> a(n), pre(n+1), suff(n+1);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        pre[i+1] = a[i] + i;
        suff[i+1] = a[i] - i;
    }

    for(int i = 2; i <= n; i++) pre[i] = max(pre[i],pre[i-1]);
    for(int i = n - 1; i >= 1; i--) suff[i] = max(suff[i], suff[i+1]);
    int ans = 0;
    for(int i = 2; i < n; i++) {
        ans = max(ans, pre[i-1] + a[i-1] + suff[i+1]);
    }
    cout << ans << nl;
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

