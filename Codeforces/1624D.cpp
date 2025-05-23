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
    ll k;
    cin>>n>>k;
    int ans = 1;
    string s;
    cin>>s;
    ll one = 0, two = 0;
    vector<int> alpha(26);
    for(auto &x : s) {
        alpha[x - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
        one += alpha[i] % 2;
        two += alpha[i] / 2;
    }

    int l = 2, r = n;
    while(l <= r) {
        int mid = (l + r) >> 1;
        bool ok = true;
        //cerr << mid << nl;
        if(mid & 1) {
            if(one + two * 2 < k) {
                ok = false;
            }
            ll x = (2 * two - max(0ll,k - one)) / 2;
            if(x * 2 < k * (mid - 1)) {
                ok = false;
            }
        } else if(two * 2 < k * mid){
            ok = false;
        }

        if(ok) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
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

