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
ll cost[21];
void solve(){
    
    // x = 0 -> 3 coins 3 times = 9 coins
    // x = 1 -> 10 coins
    // n = 8 -> 3 + 6
    ll n,k;
    cin>>n>>k;

    // cal cost of the watermelons for each x (3^x water melons)
    // 3^x watermelons -> 3^(x+1) + x * 3^(x-1)
    int minK = 0;
    // change n watermelons base10 to base 3 format
    vector<ll> a; // number of deal to use for each 3^x watermelons range 0..2
                  // it is easy to see that if we do 3 deal of 3^x watermelons then just use 
                  // 3^(x+1) watermelons with only 1 deal!
    // minimum deal to get n watermelons
    while(n > 0) {
        a.push_back(n % 3);
        minK += n % 3;
        n /= 3;
    }

    if(minK > k) {
        cout << -1 << nl;
        return;
    }

    k -= minK; // decrease minimum deal
    k /= 2;
    // the leftover deals we can split 1 deal of 3^(x+1) to 3 deal of 3^x (2 deal increase)
    // which from the coins cal formula it is much better
    // and we need to split large deal first!
    for(int i = a.size() - 1; i > 0; i--) {
        if(a[i] <= k) {
            a[i-1] += 3ll * a[i];
            k -= a[i];
            a[i] = 0;
        } else {
            a[i-1] += 3ll * k;
            a[i] -= k;
            k = 0;
        }
    }

    ll ans = 0;
    for(int i = 0; i < (int)a.size(); i++) {
        ans += cost[i] * a[i];
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    ll cur = 1;
    for(int i = 0, x = 0; i < 21; i++, cur *= 3, x++) {
        cost[i] = cur * (x + 9ll) / 3ll;
    }
    
    //setIO("");
    cin>>t;
    while(t--)solve();
    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

