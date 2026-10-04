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
    
    int n,q; cin>>n>>q;
    vector<ll> a(n+1), p(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        p[i] = p[i-1] + a[i];
    }

    for(int i = 1; i <= q; i++) {
        ll l,b; cin>>l>>b;
        ll lo = l, hi = n;
        ll target = -1;
        while(lo <= hi) {
            ll mid = lo + (hi - lo + 1) / 2;
            if(p[mid] - p[l-1] <= b) {
                target = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if(target == -1) {
            target = l - 1;
        }
        cout << target << nl;
    }
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

