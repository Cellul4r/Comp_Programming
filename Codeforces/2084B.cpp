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

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve(){
    
    int n;
    cin>>n;
    vector<ll> a(n);
    multiset<ll> cnt;
    for(int i = 0; i < n; i++) {
        ll x;
        cin>>x;
        cnt.insert(x);
        a[i] = x;
    }
    // if number of 1s is greater than 1 YES
    // now the case left is distinct value of the array  
    sort(all(a));
    if(cnt.count(a[0]) >= 2) {
        cout << "YES" << nl;
        return;
    }
    ll gcd_ = 0;
    int has = 0;
    for(int i = 1; i < n ; i++) {
        if(a[i] % a[0] == 0) gcd_ = gcd(a[i], gcd_);
        if(a[i] % a[0] == 0 && (a[i] / a[0]) % a[0] != 0) {
            has++;
        }
        if(gcd_ == a[0]) {
            cout << "YES" << nl;
            return;
        }
    }
    //cout << (has >= 2 ? "YES" : "NO") << nl;
    //return;
    gcd_ = 0;
    for(int i = n-1; i > 0 ; i--) {
        if(a[i] % a[0] == 0) gcd_ = gcd(a[i], gcd_);
        if(gcd_ == a[0]) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

