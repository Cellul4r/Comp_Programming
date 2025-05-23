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
const int N =6e6+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

bool isPrime[N];
vector<int> prime;
void sieve() {

    memset(isPrime, true, sizeof isPrime);
    isPrime[0] = isPrime[1] = false;
    for(int i = 2; i * i < N; i++) {
        if(isPrime[i]) {
            for(int j = 2 * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for(int i = 2; i < N; i++) {
        if(isPrime[i]) prime.push_back(i);
    }
}
void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    sort(all(a));
    int ans = n - 1;
    int l = 0, r = n - 2;
    while(l <= r) {
        bool ok = true;
        int mid = l + (r - l) / 2;
        ll sum = 0;
        int idx = 0;
        for(int i = mid; i < n; i++) {
            sum += 1ll * (a[i] - prime[idx++]);
        }
        //cerr << mid << " " << sum << nl;
        if(sum < 0) {
            ok = false;
        }
        if(ok) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */
    sieve();
    //cerr << prime.size() << nl;
    cin>>t;
    while(t--)solve();

    return 0;
}

