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
    ll h;
    cin>>n>>h;
    vector<ll> a(n);
    for(auto &x : a) cin>>x;
    a.push_back(1e18+1e9);
      
    auto f = [&](ll k) {
        ll now = h;
        for(int i = 0; i < n && now > 0; i++) {
            ll hp = min(a[i+1] - a[i], k);
            now -= hp;
        }
        return now <= 0;
    };

    ll l = 1, r = 1e18;
    while(l < r) {
        ll mid = l + (r - l) / 2ll;
        if(f(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << nl;
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

