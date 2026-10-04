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
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n,q;
ll a[N];
ll pre[N];
void solve(){

    cin>>n>>q;
    for(int i = 0; i < n; i++) {
        ll x; cin>>x;
        a[i] = x;
        pre[i+1] = x + pre[i];
    }

    int now = 0;
    for(int i = 0; i < q; i++) {
        int op; cin>>op;
        if(op == 1) {
            int c; cin>>c;
            now = (now + c) % n; 
        } else {
            int l,r;
            cin>>l>>r;
            l--;
            r--;
            l = (l + now) % n;
            r = (r + now) % n;

            ll ans = 0;
            if(l <= r) {
                ans = pre[r+1] - pre[l];
            } else {
                ans = pre[n] - pre[l] + pre[r+1];
            }
            cout << ans << nl;
        }
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

