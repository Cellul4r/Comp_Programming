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
const int N =2e5+2;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n;
    ll m;
    cin>>n>>m;

    ll k = 0;
    for(int i = 0; i < n; i++) {
        int l; cin>>l;  
        int mex = 0, mex2 = 0;
        vector<int> a(l);
        for(auto &x : a) cin>>x;
        sort(all(a));
        for(auto &x : a) {
            if(x == mex) mex++;
        }
        for(auto &x : a) {
            if(mex == mex2) mex2++;
            if(x == mex2 || mex == mex2) mex2++;
            if(mex == mex2) mex2++;
        }
        //cout << mex << " " << mex2 << nl;
        k = max(k,1ll*mex2);
    }

    ll ans = max(0ll,m * (m + 1) / 2ll - k * (k + 1) / 2ll);
    ans += k * min(m+1,k+1);
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

