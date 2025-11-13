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
    bool odd = false, two = false;
    vector<ll> a(n);
    for(auto &x : a) {
        cin>>x;
        if(x & 1) odd = true;
        if(x == 2) two = true;
    }
    if(odd) {
        cout << 2 << nl;
        return;
    }
    if(two) {
        cout << 3 << nl;
        return;
    }
    // all elements is even
    // x = a[i] - 1 or a[i]+1
    // ans is odd
    ll ans = LINF;
    for(auto &x : a) {
        ans = min(ans, x - 1ll);
        ll tmp = x;
        while(tmp % 2 == 0) {
            tmp /= 2ll;
        }
        if(tmp > 1) {
            ans = min(ans, tmp - 1);
        }
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

