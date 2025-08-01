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
ll power(ll base, ll exp) {
    ll res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) res *= base;
        base *= base;
        exp /= 2;
    }
    return res;
}
ll a,b;
bool check(ll k) {
    ll n = k - 1;
    if(n == 0) return false;
    // check logk(a) is integer or not
    ll tmp = a, cnt = 0;
    ll s = 0, now = 1;
    while(tmp % k == 0) {
        s += 1ll * tmp * now;
        cnt++;
        now *= n;
        tmp /= k;
    }
    if(tmp != 1) return false;
    if(now != b) return false; 
    s += now; 
    ll all;
    if(n == 1) {
        all = cnt + 1;
    } else {
        all = 1ll * (power(n,cnt+1) - 1) / (1ll * n - 1);
    }
    cout << all - now << " " << s << nl;
    return true;
}
void solve(){
    
    cin>>a>>b;
    while(a != 0 && b != 0) {
        // edge case!
        if(a == 1) {
            cout << 0 << " " << 1 << nl;
        } else {
            for(ll i = 1; i * i <= a; i++) {
                if(a % i != 0) continue;
                if(check(i)) {
                    break;
                }
                if(check(a / i)) {
                    break;
                }
            }
        }
        cin>>a>>b;
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

