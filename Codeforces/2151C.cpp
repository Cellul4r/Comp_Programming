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
    
    int n; cin>>n;
    vector<ll> a(2*n+1);
    for(int i = 1; i <= 2*n; i++) cin>>a[i];
    // 4 5 6 9 
    // 1 2 3 4
    // k = 1 1|3 - 2,4
    // k = 2 1,2 - 3,4
    // k = 1 exit at idx 2, 4
    // k = 2 exit at idx 3, 4
    //4
    // 6149048 26582657 36124499 43993239 813829899 860114890 910238130 913669539
    // k = 1 exit at idx 2, 4, 6, 8, ...
    // k = 1 1|,3,5,7 - 2,4,6,|8
    // k = 2 1,2|,4,6 - 3,5,|7,8
    // k = 3 1,2,3|,5 - 4,|6,7,8
    // k = 4 1,2,3,4| - |5,6,7,8

    vector<ll> b(2*n+1), c(2*n+1);
    for(int i = 1; i <= 2*n; i+= 2) {
        if(i-2>=0) b[i] = b[i-2] + a[i];
    }
    for(int i = 2; i <= 2*n; i+= 2) {
        c[i] = c[i-2] + a[i];
    }
    ll lft = 0, rgt = 0;
    for(int i = 1,l=1,r=2*n; i <= n; i++,l++,r--) {
        lft += a[l];
        rgt += a[r];
        ll ans = rgt - lft;
        ll idx = 2 * n - i;
        if(i & 1) {
            if(idx > i) {
                ans -= b[idx] - b[i]; 
                ans += c[idx-1] - c[i-1];
            }
        } else {
            if(idx > i) {
                ans -= c[idx] - c[i];
                ans += b[idx-1] - b[i-1];
            }
        }
        cout << ans << " ";
    }
    cout << nl;
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

