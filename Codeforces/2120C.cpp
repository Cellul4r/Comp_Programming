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
    ll m;
    cin>>n>>m;
    ll sum = 1ll * n * (n + 1) / 2ll;
    if(m < n || m > sum) {
        cout << -1 << nl;
        return;
    }

    vector<int> a(n);
    int l = 1;
    m -= n;
    for(int i = 1; i <= n; i++) {
        ll k = min(1ll * n - i, m);
        a[k] = l++;
        if(k == 0) break;
        m -= min(m, k);
    }
    for(int i = 0; i < n; i++) {
        if(a[i] == 0) a[i] = l++;
    }
    cout << a[0] << nl;
    for(int i = 0; i < n - 1; i++) {
        cout << a[i] << " " << a[i+1] << nl;
    }
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

