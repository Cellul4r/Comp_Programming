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
    cin>>n;
    vector<ll> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    ll k = n * a[0] - a[n-1];
    if(k % (n * n - 1) != 0) {
        cout << "NO" << nl;
        return;
    }
    ll y = k / (1ll * n * n - 1);
    ll x = a[0] - y * n;
    if(x < 0 || y < 0) {
        cout << "NO" << nl;
        return;
    }

    for(int i = 0; i < n; i++) {
        if((i+1) * x + (n - i) * y != a[i]) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;

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

