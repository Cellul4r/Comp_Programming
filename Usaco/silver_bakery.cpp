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
    ll c,m;
    cin>>n>>c>>m;
    vector<array<ll,3>> a(n);
    for(auto &x : a) {
        cin>>x[0]>>x[1]>>x[2];
    }
    
    auto f = [&](int k) {
        ll l = max(1ll, m - k);
        ll r = min(m, c + m - k - 1);
        for(int i = 0; i < n; i++) {
            ll aa = a[i][0], bb = a[i][1], cc = a[i][2];
            ll d = c + m - k;
            if(bb - aa > 0) {
                r = min(r, (cc - aa * d) / (bb - aa)); 
            } else if(bb - aa < 0) {
                l = max(l, (-cc + aa * d + aa - bb - 1) / (aa - bb));
            } else {
                if(cc < aa * d) {
                    return false;
                }
            }
        }
        return l <= r;
    };
    ll l = 0, r = c + m - 2;
    while(l < r) {
        ll mid = l + (r - l) / 2;
        //cerr << mid << nl;
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

