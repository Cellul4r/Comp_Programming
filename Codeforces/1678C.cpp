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
    
    int n; cin>>n;
    vector<int> p(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>p[i];
    }
    ll ans = 0;
    vector<ll> pref(n+1,0);
    for(int i = 2; i < n - 1; i++) {
        // i -> choose index b
        //cerr << i - 1 << " : " << p[i-1] << " " << pref[p[i-1]] << nl;
        for(int k = p[i-1]; k <= n; k++) {
            pref[k]++;
        }
        // j -> choose index c
        ll cur = 0;
        for(int j = n - 1; j > i; j--) {
            if(p[j+1] < p[i]) {
                cur++;
            }
            //cerr << i << " " << j << " : " << p[j] << " " << pref[p[j]] << nl;
            ans += cur * pref[p[j]];
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

