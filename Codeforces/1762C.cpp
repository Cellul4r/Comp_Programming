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
const int N =2e5+1;
const int INF = 998244353;
const ll LINF = 1e18+7;

int pow2[N];
void solve(){
    
    int n;
    string s;
    cin>>n>>s;
    int ans = 0;
    int zero = 0, one = 0;
    int empty = 0;
    for(int i = 0; i < n; i++) {
        int k;
        //cerr << zero << " " << one << " " << empty << nl;
        if(s[i] == '0') {
            zero++;
            int want = max(0, i + 1 - zero);
            if(want == 0) {
                if(i > 0) empty++;
                k = pow2[empty];
            } else {
                int now = min(want, empty);
                want -= now;
                empty -= now;
                zero += now;
                if(want == 0) k = 2;
                else {
                    want--;
                    if(want == 0) {
                        zero++;
                        k = 1;
                    } else {
                        k = 0;
                        break;
                    }
                }
            }
        }
        else {
            one++;
            int want = max(0, i + 1 - one);
            if(want == 0) {
                if(i > 0) empty++;
                k = pow2[empty];
            } else {
                int now = min(want,empty);
                want -= now;
                empty -= now;
                one += now;
                if(want == 0) k = 2;
                else {
                    want--;
                    if(want == 0) {
                        one++;
                        k = 1;
                    } else {
                        k = 0;
                        break;
                    }
                }
            }
        }
        //cerr << k << nl;
        ans += k;
        ans %= INF;
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    pow2[0] = 1;
    for(int i = 1; i < N; i++) {
        pow2[i] = pow2[i-1] * 2;
        pow2[i] %= INF;
    }
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

