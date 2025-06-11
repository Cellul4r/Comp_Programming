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

void solve(){
    
    int k;
    cin>>k;
    // 1111 = 11 * 100 + 11
    // 11111 = 111 * 100 + 11
    // k must be in the form of 11x + 111y = k, x >= 0 and y >= 0
    // 11x = k - 111y
    // x = (k - 111y) / 11, must be divisible by 11
    for(int i = 0; i * 111ll <= k; i++) {
        int x = k - 111 * i;
        if(x % 11 == 0 && x >= 0) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
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

