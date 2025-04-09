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

bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a / gcd(a,b) * b;
}
int f(int a, int b) {
    return lcm(a,b) / gcd(a,b);
}

vector<int> p;
bool prime[10000001];
void sieve() {
    int N = 1e7+1;
    memset(prime, true, sizeof prime);
    prime[0] = prime[1] = false;
    for(int i = 1; i * i < N; i++) {
        if(prime[i]) {
            for(int j = 2 * i; j < N; j += i) {
                prime[j] = false;
            }
        }
    }

    for(int i = 1; i < N; i++) {
        if(prime[i]) {
            p.push_back(i);
        }
    }
}
void solve(){
    
    int n;
    cin>>n;
    ll ans = 0;
    /*for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            if(isPrime(f(i,j))) {
                cerr << i << " " << j << nl;
            }
        }
    }*/

    for(auto &x : p) {
        //cerr << x << " ";
        if(x > n) {
            break;
        }
        ll k = n / x;
        ans += k;
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    sieve();
    cin>>t;
    while(t--)solve();

    return 0;
}

