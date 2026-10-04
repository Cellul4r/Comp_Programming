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
int lcm(int a, int b) {
    return a * b / gcd(a,b);
}
void test(int n) {

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if(gcd(lcm(i,j),lcm(j,k)) == gcd(i,k)) {
                    cout << i << " " << j << " " << k << nl;
                    ans++;
                }
            }
        }
    }
    cout << ans << nl;
}
void solve(){
    
    int n; cin>>n;
    // 1 5 11 22 32 52 66 92 147
    // gcd(lcm(a,b), lcm(b,c)) = gcd(a,c)
    // gcd(x) = gcd(a,c)
    // gcd(x) >= b
    // gcd(a * b / gcd(a,b), b * c / gcd(b,c)) = gcd(a,c)
    //test(n);
    ll ans = 0;
    for(int b = 1; b <= n; b++) {
        ans += (1ll * n / b) * (1ll * n / b);
        // <F12>
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

