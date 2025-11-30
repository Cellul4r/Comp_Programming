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
    ll cnt = 0;
    for(int i = 0; i < 2 * n; i++) {
        int x; cin>>x;
        assert(x >= 1 && x <= 2 * n);
        if(a[x] == 0) cnt++;
        a[x]++;
    }

    ll ans = 0;
    ll even = 0, odd = 0;
    for(int i = 1; i <= 2 * n; i++) {
        if(a[i] == 0) continue;
        if(a[i] & 1) {
            odd++;
        } else {
            even++;
        }
    }
    ans = 2 * even + odd;
    if(odd == 0 && even % 2 != n % 2) {
        ans -= 2;
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

