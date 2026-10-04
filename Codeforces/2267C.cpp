/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =3e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
vector<int> primes[N];
bool isPrime[N];
void init() {
    
    memset(isPrime, true, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i < N; i++) {
        if(isPrime[i]) {
            primes[i].push_back(i);
            for(int j = 2*i; j < N; j += i) {
                if(j % i == 0) {
                    primes[j].push_back(i);
                    isPrime[j] = false;
                }
            }
        }
    }
}
void solve(){
    
    int n,x; cin>>n>>x;
    vector<int> a(n+1);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    for(auto &p : primes[x]) {
        ll cur = 0;
        for(int i = 1; i <= n; i++) {
            bool ok = false;
            for(auto &j : primes[a[i]]) {
                if(j == p) {
                    ok = true;
                    break;
                }
            }
            if(ok) {
                cur += 1ll * a[i];
            }
        }
        ans = max(ans, cur);
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    init();
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

