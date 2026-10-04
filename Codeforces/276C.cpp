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
    
    int n,q;
    cin>>n>>q;
    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    // difference array
    vector<ll> d(n+1);
    for(int i = 1; i <= q; i++) {
        int l, r; cin>>l>>r;
        d[l]++;
        if(r+1 <= n) {
            d[r+1]--;
        }
    }
    // prefix sum to get each element
    for(int i = 1; i <= n; i++) {
        d[i] += d[i-1];
    }
    // sort in decreasing order (large -> small)
    sort(a.begin()+1,a.end(), greater<ll>());
    sort(d.begin()+1,d.end(), greater<ll>());
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans += a[i] * d[i];
    }
    cout << ans << nl;
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

