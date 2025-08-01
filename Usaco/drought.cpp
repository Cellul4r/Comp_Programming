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

int n;
int a[N];
void solve(){

    cin>>n;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    for(int i = 0; i < n - 1; i++) {
        if(a[i] < a[i+1]) {
            // need to decrease a[i+1] to a[i]
            // how? decrease a[i+1] and a[i+2]
            if(i + 2 >= n) {
                cout << -1 << nl;
                return;
            }

            ll diff = a[i+1] - a[i];
            a[i+1] -= diff;
            a[i+2] -= diff;
            if(a[i+2] < 0) {
                cout << -1 << nl;
                return;
            }
            ans += 2ll * diff;
        } else if(a[i] > a[i+1]) {
            if((i+1) & 1) {
                cout << -1 << nl;
                return;
            }

            ll diff = a[i] - a[i+1];
            ans += (i + 1) * diff;
        }
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

