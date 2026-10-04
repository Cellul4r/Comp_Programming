/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e6+1;
const int INF = 1e9+7;
const ll LINF = 998244353;

void setIO(string);
ll fact[N];
ll mul(ll a, ll b) {
    a = a * b % LINF;
    return a;
}
ll pow(ll x, ll y) {
    if(y == 0) return 1ll;
    ll t = pow(x, y / 2ll);
    if(y & 1) {
        return (x * t % LINF) * t % LINF;
    }
    return t * t % LINF;
}
void solve(){
    
    int n; cin>>n;
    string s; cin>>s;
    // reverse operation with s[l] = s[r] -> f(l,r)
    // reverse f(l,l+1) if s[l] = s[l+1] is useless operation
    // trivial function f(l,r) if string is palindrome -> useless operation
    //
    // if string s is palindrome -> the answer is 1
    // no idea right now how to count?
    // it is binary string -> how can we use from this property?
    // split into the group of zero and ones?
    // the reverse operation in the group does not thing because the group of zero or one is always a palindrome string
    // star and bars grouping
    // after we group one and zero we know that the operation can swap the number of zero in each group
    // n!/(n-k)!*k!
    ll o = 0, z = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') z++;
        else o++;
    }
    ll go = 0, gz = 0;
    char cur = s[0];
    for(int i = 1; i < n; i++) {
        if(s[i] == cur) continue;
        if(cur == '0') {
            gz++;
        } else {
            go++;
        }
        cur = s[i];
    }
    if(cur == '0') {
        gz++;
    } else {
        go++;
    }
    ll one = 1, zero = 1;
    if(o >= 1) {
        one = fact[o-1] * pow(mul(fact[o-go],fact[go-1]), LINF - 2) % LINF;
    }
    if(z >= 1) {
        zero = fact[z-1] * pow(mul(fact[z-gz],fact[gz-1]), LINF - 2) % LINF;
    }
    cout << mul(one,zero) << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    fact[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = fact[i-1] * i % LINF;
    }
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

