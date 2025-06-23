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
    
    int n,k,x;
    cin>>n>>k>>x;

    if(x != 1) {
        cout << "YES" << nl << n << nl;
        for(int i = 1; i <= n; i++) {
            cout << 1 << " ";
        }
        cout << nl;
        return;
    }

    // x = 1
    if(n % 2 == 0 && k >= 2) {
        cout << "YES" << nl << n / 2 << nl;
        for(int i = 1; i <= n / 2; i++) {
            cout << 2 << " ";
        }
        cout << nl;
        return;
    }
    if(n % 2 == 0 && k < 2) {
        cout << "NO" << nl;
        return;
    }
    // n is odd
    if(n == 1 || k < 3) {
        cout << "NO" << nl;
        return;
    }

    cout << "YES" << nl << n / 2 << nl;
    while(n > 3) {
        cout << 2 << " ";
        n -= 2;
    }
    cout << 3;
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

