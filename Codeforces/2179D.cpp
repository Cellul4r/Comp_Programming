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
void test(int n) {
    vector<int> a(n);
    iota(all(a), 0);
    do {
        int cur = a[0];
        int ans = __builtin_popcount(cur);
        for(int i = 1; i < n; i++) {
            cur = cur & a[i]; 
            ans += __builtin_popcount(cur);
        }
        for(auto &x : a) {
            cout << x << " ";
        }
        cout << " WITH: " << ans << nl;
        if(ans == 7) break;
    } while(next_permutation(all(a)));
}
void solve(){
    
    int n; cin>>n;
    int k = (1 << n);
    //test(k);
    cout << k - 1 << " ";
    for(int i = n - 1; i >= 0; i--) {
        int left = n - i;
        for(int j = 0; j < (1 << left); j += 2) {
            cout << ((1 << i) - 1 + j * (1 << i)) << " ";
        }
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

