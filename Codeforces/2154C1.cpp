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
const int N =2e5+2;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
vector<int> primes[N];
void init() {

    for(int i = 2; i < N; i++) {
        if(!primes[i].empty()) continue;
        for(int j = i; j < N; j += i) {
            primes[j].push_back(i);
        }
    }
}
void solve(){

    int n;
    cin>>n;

    vector<int> a(n),b(n);
    int even = 0;
    for(auto &x : a) {
        cin>>x;
        if(x % 2 == 0) even++;
    }
    for(auto &x : b) {
        cin>>x;
        assert(x == 1);
    }

    if(even >= 2) {
        cout << 0 << nl;
        return;
    }

    // find if there are pair of gcd > 1
    vector<int> prime(2e5+2);

    for(auto &x : a) {
        for(auto &y : primes[x]) {
            prime[y]++;
        }
    }

    for(auto &x : prime) {
        if(x >= 2) {
            cout << 0 << nl;
            return;
        }
    }

    for(auto &x : a) {
        for(auto &y : primes[x]) {
            prime[y]--;
        }

        for(auto &y : primes[x+1]) {
            if(prime[y] >= 1) {
                cout << 1 << nl;
                return;
            }
        }

        for(auto &y : primes[x]) {
            prime[y]++;
        }
    }
    cout << (even == 1 ? 1 : 2) << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    init();
    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

