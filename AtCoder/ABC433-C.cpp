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
    
    string s;
    cin>>s;
    int n = s.length();
    ll ans = 0;
    for(int dig = 0; dig < 9; dig++) {
        int i = 0;
        while(i < n) {
            if(s[i] - '0' != dig) {
                i++;
                continue;
            }
            int j = i;
            int cnt = 0;
            while(j < n && s[j] - '0' == dig) {
                j++;
                cnt++;
            }
            // find next digit+1
            int cnt2 = 0;
            while(j < n && s[j] - '0' == dig+1) {
                j++;
                cnt2++;
            }
            //cerr << dig << " " << i << " " << j << nl;
            ll k = min(cnt,cnt2);
            ans += k;
            i = j;
        }
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

