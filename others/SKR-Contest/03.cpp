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

void solve(){
    
    int n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for(auto &x : a) cin>>x;
    ll ans = INF;
    ll l = 1, r = 1e16+1;
    while(l <= r) {
        ll mid = l + (r - l) / 2ll;
        int now = k;
        ll w = 0;
        for(int i = n-1; i >= 0; i--) {
            if(w + a[i] > mid) {
                now--;
                w = a[i];
                if(mid < a[i]) {
                    now = 0;
                    break;
                }
            } else{
                w += a[i];
            }
        }
        now--;
        if(now >= 0) {
            //cerr << mid << " " << now << nl;
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

