/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n;
    ll m; cin>>n>>m;

    vector<ll> a,b;
    a.push_back(0);
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        a.push_back(x);
    }
    a.push_back(m);
    n += 2; 
    ll even = 0, odd = 0;
    ll ans = 0;
    for(int i = 0; i < n - 1; i++) {
        if(i % 2 == 0) {
            even += a[i+1] - a[i];
        } else {
            odd += a[i+1] - a[i];
        }
    }
    ans = even;
    ll cur = 0;
    for(int i = 0; i < n - 1; i++) {
        // insert value x after index i
        // edge case 2 contiguous elements
        if(a[i+1] - a[i] == 1) {
            if(i % 2 == 0) {
                cur += 1;
            } else {
                odd -= 1;
            }
            continue;
        }
        ll now;
        if(i % 2 == 0) {
            now = odd + cur; 
            //ll x = a[i+1] - 1;
            now += a[i+1] - a[i] - 1;
            cur += a[i+1] - a[i];
            ans = max(ans, now);
        } else {
            odd -= a[i+1] - a[i];
            now = odd + cur;
            //ll x = a[i] + 1;
            now += a[i+1] - a[i] - 1;
            ans = max(ans, now);
        }
        //cout << now << nl;
    }
    // a0 x a1 -> up for x - a0, a2 - a1
    // a0 = 1
    // a0 a1 -> the lamp is lit for a1 - a0 unit of time, up
    // a1 a2 -> 0 down
    // a2 a3 -> a3 - a2 up
    // a3 a4 -> 0 down
    // a4 a5 -> a5 - a4  up
    // ...
    // an M -> M - an if n is even else 0
    // thus now is a[1] - 1 , a[3] - a[2], a[5] - a[4]
    cout << ans << nl;
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

