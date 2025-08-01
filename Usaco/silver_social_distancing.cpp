/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
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
    
    int n,m;
    cin>>n>>m;
    vector<pl> a(m);
    for(auto &x : a) {
        cin>>x.first>>x.second;
    }
    sort(all(a));

    auto f = [&](ll x) {
        int cows = 0;
        int i = 0;
        ll prev_ = -(ll)1e18;
        while(i < m && cows < n) {
            //cerr << i << " " << cows << " " << prev_ << nl;
            ll k = max(prev_+x,a[i].first);
            if(k >= a[i].first && k <= a[i].second) {
                cows++;
                prev_ = k;
                continue;
            }
            k = max(prev_+x, a[i].second);
            if(k >= a[i].first && k <= a[i].second) {
                cows++;
                prev_ = k;
                continue;
            }
            i++;
        }
        //cerr << x << " " << cows << nl;
        return cows >= n;
    };
    ll l = 1, r = 1e18;
    while(l < r) {
        ll mid = l + (r - l+1) / 2;
        if(f(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    setIO("socdist");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

