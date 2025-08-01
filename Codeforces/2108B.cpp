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
void test() {

    for(int x = 0; x <= 80; x++) {
        bool found = false;
        int minSum = INF;
        for(int i = 1; i <= 100 && !found; i++) {
            for(int j = 1; j <= 100 && !found; j++) {
                for(int k = 1; k <= 100 && !found; k++) {
                    if((i^j^k) == x) {
                        minSum = min(minSum, i+j+k);
                        //cout << x << ": " << i << " " << j << " " << k << nl;
                    }

                }
            }
        }
        cout << x << ": " << minSum << nl;
    }
}
void solve(){
    
    int n,x;
    cin>>n>>x;
    //test();
    if(n == 1 && x == 0) {
        cout << -1 << nl;
        return;
    }
    int cnt = __builtin_popcount(x);
    if(cnt >= n) {
        cout << x << nl;
        return;
    }
    // cnt < n
    int k = n - cnt;
    ll sum = 0;
    if(k & 1) {
        if(x == 1) {
            for(int i = 0; i < 31; i++) {
                if((1 << i) & x) sum += (1 << i);
            }
            sum += k - 1 + 4;
        } else if(x > 1) {
            for(int i = 0; i < 31; i++) {
                if((1 << i) & x) sum += (1 << i);
            }
            sum += k + 1;
        } else {
            // x = 0
            for(int i = 0; i < 31; i++) {
                if((1 << i) & x) sum += (1 << i);
            }
            sum += k - 1 + 4;
        }
    } else {
        for(int i = 0; i < 31; i++) {
            if((1 << i) & x) sum += (1 << i);
        }
        sum += k;
    }
    cout << sum << nl;
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

