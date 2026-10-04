/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n;
    ll c,d;
    cin>>n>>c>>d;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    sort(all(a), greater<ll>());
    int l = -1,r=d-1;
    // if l == -1 -> always return true -> imppossible k >= 0
    // if l == d-1 -> INFINITY
    auto f = [&](int k) {
        if(k == -1) return true;
        k++;
        ll sum = 0;
        // split to ceil(d / k) segments
        // each segments has length of k
        // except the last segment has length of d mod k 
        int tot = d / k;
        for(int i = 0; i < min(n,k); i++) {
            sum += 1ll * tot * a[i];
        }
        tot = d % k;
        for(int i = 0; i < min(tot,n); i++) {
            sum += a[i];
        }
        //cout << k << " : " << sum << " " << c << " " << (sum >= c ? "Y" : "N") << nl;
        return sum >= c;
    };
    while(l < r) {
        int m = l + (r - l + 1) / 2;
        if(f(m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }
    if(l == -1) {
        cout << "Impossible\n";
    } else if(l == d - 1) {
        cout << "Infinity\n";
    } else {
        cout << l << nl;
    }
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

