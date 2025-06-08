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
const int DIG = 19;
void setIO(string);
int n,k;
int val[10];
void solve(){
    
    cin>>n>>k;
    k++;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll now = k;
        if(i + 1 < n) now = min(k, val[a[i+1]] / val[a[i]] - 1);
        ans += val[a[i]] * now;
        k -= now;
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    val[0] = 1;
    for(int i = 1; i <= 9; i++) val[i] = val[i-1] * 10;
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

