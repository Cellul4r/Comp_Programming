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
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    int now = INF;
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        // (ceil(a[i] / x) <= now)
        // ((a[i] + x - 1) / x <= now)
        // (a[i] + x  - 1) <= now * x
        // a[i] + x - now * x - 1 <= 0
        // a[i] + x * (1 - now) - 1 <= 0
        // a[i] - x * (now - 1) - 1 <= 0
        // a[i] - 1 <= x * (now - 1)
        // x = (a[i] + now - 2) / (now - 1)
        if(a[i] <= now) {
            now = a[i];
            continue;
        }
        int x = (a[i] + now - 1) / (now);
        ans += x - 1;
        now = a[i] / x;
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

