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
const int N =1e6+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
bool isPrime[N];
void sieve() {
    memset(isPrime,true,sizeof isPrime);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i < N; i++) {
        if(isPrime[i]) {
            for(int j = 2 * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
void solve(){
    
    int n,e;
    cin>>n>>e;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    ll ans = 0;
    for(int i = 0; i < e; i++) {
        int left = 0;
        for(int j = i; j < n; j += e) {
            if(a[j] == 1) {
                left++;
            } else if(isPrime[a[j]]) {
                int right = 0;
                j += e;
                while(j < n && a[j] == 1) {
                    right++;
                    j += e;
                }
                j -= e;
                ans += 1ll * left * (right + 1) + right;
                left = right;
            } else {
                left = 0;
            }
        }
    }
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

