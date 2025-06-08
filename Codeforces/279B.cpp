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
    
    int n,t;
    cin>>n>>t;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    int ans = 0;
    int l = 0,r = 0;
    int now = 0;
    while(l < n) {
        //cerr << l << " " << r << nl;
        while(r < n && a[r] <= t - now) {
            now += a[r++];
        }
        ans = max(ans, r - l);
        now -= a[l++];
    }
    ans = max(ans, r - l);
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

