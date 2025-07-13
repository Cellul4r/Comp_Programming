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

void solve(){
    
    int n;
    string s;
    cin>>n>>s;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        vector<int> cnt(10);
        for(int j = 0; j < 100 && i + j < n; j++) {
            cnt[s[i+j]-'0']++; 
            ll distinct = 0;
            for(int i = 0; i < 10; i++) {
                distinct += (cnt[i] > 0);
            }
            bool ok = true;
            for(int i = 0; i < 10; i++) {
                if(cnt[i] > distinct) ok = false;              
            }
            if(ok) ans++;
        }
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

