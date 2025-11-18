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
    
    int n; cin>>n;
    vector<ll> a(n), b(n);
    for(auto &x : a) {
        cin>>x;
    }
    for(auto &x : b) {
        cin>>x;
    }
    sort(all(a), greater<ll>());
    sort(all(b), greater<ll>());
    for(int i = 1; i < n; i++) {
        a[i] += a[i-1];
        b[i] += b[i-1];
    }

    int l = 0, r = n;
    while(l < r) {
        int mid = l + (r - l) / 2;
        ll k = n + mid - (n + mid) / 4ll;
        ll x = 100ll * mid + a[k-mid-1];
        ll y = b[min(k,1ll*n)-1];
        if(x >= y) {
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

