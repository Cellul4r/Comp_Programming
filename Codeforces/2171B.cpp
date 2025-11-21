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
    
    int n; cin>>n;
    vector<ll> a(n);
    for(auto &x : a) cin>>x;
    for(int i = 1; i < n - 1; i++) {
        if(a[i] == -1) a[i] = 0;
    }
    ll ans = 0;
    if(a[0] != -1 && a[n-1] != -1) ans = abs(a[0] - a[n-1]);
    else if(a[n-1] != -1){
        a[0] = a[n-1];
    } else if(a[0] != -1){
        a[n-1] = a[0];
    } else {
        a[0] = a[n-1] = 0;
    }
    cout << ans << nl;
    for(auto &x : a) {
        cout << x << " ";
    }
    cout << nl;
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

