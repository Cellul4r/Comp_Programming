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
const int N =3e5+1;
ll INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
// find prime <= 5000
bool isPrime[5001];
int cnt[5001];
int a[N];
vector<int> primes;
void check() {

    for(int i = 2; i <= 5000; i++) {
        bool ok = true;
        for(int j = 2; j * j <= i; j++) {
            if(i % j == 0) {
                ok = false;
            }
        }
        if(ok) isPrime[i] = true;
    }
    for(int i = 1; i<= 5000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    }

}

ll powMod(ll x, ll y) {
    if(y == 0) return 1ll;
    ll t = powMod(x, y / 2ll);
    if(y & 1) {
        return (x * t % INF) * t % INF;
    }
    return t * t % INF;
}
void solve(){

    int n; cin>>n;
    ll sum = 0;
    memset(cnt, 0, sizeof cnt);
    for(int i = 0; i < n; i++) {
        ll c; cin>>c;
        sum += c;
        a[i] = c;
    }

    for(int i = 2; i <= sum; i++) {
        int tmp = i;
        for(auto &x : primes) {
            while(tmp % x == 0) {
                tmp /= x;
                cnt[x]++;
            }
        }
    }
    
    int mx = 0;
    for(int i = 0; i < n; i++) mx = max(mx, a[i]);
    vector<int> save(5002);
    for(int i = 0; i < n; i++) {
        save[2]++;
        save[a[i]+1]--;
    }
    for(int i = 1; i <= 5000; i++) {
        save[i] += save[i-1];
    }
    for(int i = 1; i <= mx; i++) {
        if(save[i] == 0) continue;
        int tmp = i;
        for(auto &x : primes) {
            while(tmp % x == 0) {
                tmp /= x;
                cnt[x] -= save[i];
            }
        }
    }
    ll ans = 1;
    for(auto &x : primes) {
        ans = ans * powMod(x,cnt[x]) % INF;
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    check();
    cin>>t>>INF;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

