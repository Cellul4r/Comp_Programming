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
    
    ll k,x;
    cin>>k>>x;

    auto f = [&](ll mess) {
        ll sum = 0;
        sum += k * k * (mess / (2ll * k - 1));
        ll left = mess % (2ll * k - 1);
        sum += k * k;
        if(left < k) {
            ll now = k;
            sum -= now * (now + 1) / 2ll;
            sum -= now * (now - 1) / 2ll - left * (left + 1) / 2ll;
        } else {
            ll now = 2ll * k - 1 - left;
            sum -= now * (now + 1) / 2ll;
        }
        //cerr << mess << " " << sum << nl;
        return sum < x;
    };

    ll l = 0, r = 2ll * k - 2;
    while(l < r) {
        ll mid = l + (r - l + 1) / 2ll;
        if(f(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l+1 << nl;
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

