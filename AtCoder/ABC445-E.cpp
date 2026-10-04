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
const int N =1e7+1;
const ll INF = 998244353;
const ll LINF = 1e18+7;

void setIO(string);
vector<int> lpf(N), primes;
ll poww(ll x, ll y) {
    if(y == 0) return 1ll;
    ll t = poww(x, y / 2ll); 
    if(y & 1) {
        return (t * t % INF) * x % INF;
    }
    return t * t % INF;
}
void solve(){
    
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    map<int,int> e1,e2;
    for(int i = 1; i <= n; i++) {

        int x = a[i];
        while(x > 1) {
            int p = lpf[x];
            int e = 0;
            while(x % p == 0) {
                x /= p;
                e++;
            }
            if(e > e1[p]) {
                e2[p] = e1[p];
                e1[p] = e;
            } else if(e > e2[p]) {
                e2[p] = e;
            }
        }
    }

    // find lcm(a1,..,an)
    ll ans = 1;
    for(auto &[x, y] : e1) {
        ans = ans * poww(x, y) % INF;
    }

    for(int i = 1; i <= n; i++) {
        // exclude a[i]
        // ans / a[i] % INF
        int x = a[i];
        ll now = ans;
        while(x > 1) {
            int p = lpf[x];
            int e = 0;
            while(x % p == 0) {
                x /= p;
                e++;
            }
            if(e == e1[p]) {
                now = now * poww(poww(p, e1[p] - e2[p]), INF - 2) % INF;
            }
        }
        cout << now << " ";
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    for(int i = 2; i <= N; i++) {
        if(lpf[i] == 0) {
            lpf[i] = i;
            primes.push_back(i);
        }

        for(auto &x : primes) {
            if(x * i > N || x > lpf[i]) break;
            lpf[x * i] = x;
        }
    }
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

