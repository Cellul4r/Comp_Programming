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
    ll c;
    cin>>n>>c;
    vector<ll> a(n);
    for(auto &x : a) cin>>x;
    for(int i = 1; i < n; i++) a[i] += a[i-1];
    int ans = -1;
    ll mn = LINF;
    for(int i = 0; i < n; i++) {
        ll k = a[i] + 1;
        ll wait = (k + c - 1) / c - 1;
        //cout << i << " VAL: " << k << " -> " << wait << nl;
        ll val = max(0ll, wait - i);
        if(wait < n && val < mn) {
            mn = val;
            ans = i;
        }
    }
    if(ans == -1) {
        cout << "impossible";
        return;
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

