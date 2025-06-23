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
const int N =3200+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
bool isPrime(int x) {
    if(x <= 1) return false;
    for(int i = 2; i * i <= x; i++) {
        if(x % i != 0) continue;
        return false;
    }
    return true;
}
void test() {

    for(int i = 2; i <= 500; i++) {
        int prime = 0, divi = 0;
        for(int j = 1; j * j <= i; j++) {
            if(i % j != 0) continue; 
            if(isPrime(j)) {
                prime++;
            } else if(j != 1){
                divi++;
            }
            if(i / j != j) {
                if(isPrime(i / j)) {
                    prime++;
                } else if(i / j != 1){
                    divi++;
                }
            }
        }
        //cerr << prime << " " << divi << nl;
        if(divi >= prime) {
            cerr << i << nl;
        }
    }
}

bool isprime[N];
vector<int> prime;
void sieve() {
    memset(isprime, true, sizeof isprime);
    isprime[0] = isprime[1] = false;
    for(int i = 2; i * i < N; i++) {
        if(isprime[i]) {
            for(int j = 2 * i; j < N; j += i) {
                isprime[j] = false;
            }
        }
    }

    for(int i = 1; i < N; i++) {
        if(isprime[i]) {
            prime.push_back(i);
        }
    }
}
void solve(){
    //test();
    int n;
    cin>>n;
    int ans = 0;
    map<int,int> cnt;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        for(auto &p : prime) {
            if(p > x) break;
            int k = 0;
            while(x % p == 0) {
                x /= p;
                k++;
            }
            if(k != 0) cnt[p] += k; 
        }
        if(x > 1) cnt[x]++;
    }
    int remain = 0;
    for(auto &[x,y] : cnt) {
        ans += y / 2;
        remain += y % 2;
    }
    ans += remain / 3;
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    sieve();
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

