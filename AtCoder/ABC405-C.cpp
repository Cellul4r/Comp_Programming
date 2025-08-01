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

int n;
void solve(){
    
    cin>>n;
    vector<ll> pre(n+1), a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        pre[i] = a[i] + pre[i-1];
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += a[i] * (pre[n] - pre[i]);
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

