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
    
    int n,k; cin>>n>>k;
    vector<ll> a(n), b(k);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    sort(all(a));
    reverse(all(a));

    sort(all(b));
    vector<bool> buy(n, true);
    for(ll i = 0, j = 0; i < k; i++) {
        if(j + b[i] - 1 < n) buy[j+b[i]-1] = false;
        j += b[i];
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        if(buy[i]) {
            ans += a[i];
        }
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

