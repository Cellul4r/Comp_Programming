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
    
    int n,m; cin>>n>>m;
    vector<ll> a(n), b(m);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;

    ll x = 0, y = 0;
    for(int i = 0; i < n-1; i++) {
        x += a[i] - a[i+1] + 1;
    }
    x += a[n-1];
    for(int i = 0; i < m-1; i++) {
        y += b[i] - b[i+1] + 1;
    }
    y += b[m-1];
    cout << (x >= y ? 1 : 2) << nl;
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

