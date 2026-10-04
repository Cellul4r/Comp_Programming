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
    ll ans = 0, ans2 = 0;
    vector<ll> a(n+1);
    ll cur = 0, cur2 = 0;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        if(a[i] > 1) {
            ans += a[i];
        } else {
            cur++;
            cur2++;
        }
    }

    ll put = 0;
    for(int i = 1; i <= n; i++) {
        ll k = min(cur, (a[i] - 2ll) / 2ll);
        ans += k;
        put += k;
        if(a[i] > 2) ans2 = max(ans2, a[i] + min(cur2, a[i] / 2ll));
        cur -= k;
    }
    if(ans == 2) {
        if(cur2 > 0) {
            ans = 3; 
        } else {
            ans = 0;
        }
    }
    ans = max(ans, ans2);
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

