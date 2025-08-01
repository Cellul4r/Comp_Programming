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
const int M = 40001;
bool isPrime[M];
vector<int> prime;
void init() {
    
    memset(isPrime, true, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i*i < M; i++) {
        if(!isPrime[i]) continue;
        for(int j = 2 * i; j < M; j += i) {
            isPrime[j] = false;
        }
    }
    for(int i = 1; i < M; i++) if(isPrime[i]) prime.push_back(i);
}
ll modPow(ll x, ll y) {
    if(y == 0) return 1;
    ll t = modPow(x, y / 2ll);
    if(y & 1) {
        return 
    }
}
void solve(){
    
    init();
    int n;
    cin>>n;

    vector<ll> save(prime.size());

    for(int i = 0; i < n; i++) {
        int x,y; cin>>x>>y;
        for(int j = 0; j < (int)prime.size(); j++) {
            ll cnt = 0;
            while(x % j == 0) {
                x /= j;
                cnt++;
            }
            cnt *= y;
            save[j] += cnt;
        }
    }

   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

