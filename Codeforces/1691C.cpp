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
    
    int n,k;
    string s;
    cin>>n>>k>>s;
    int ans = 0;  
    int ones = 0, l = n, r = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            ones++;
            l = min(l,i);
            r = max(r,i);
        }
    }
    
    if(ones > 0 && n - r - 1 <= k) {
        ones--;
        k -= n - r - 1;
        ans++;
    }
    if(ones > 0 && l <= k) {
        ones--;
        k -= l;
        ans += 10;
    }
    cout << 11 * ones + ans << nl;
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

