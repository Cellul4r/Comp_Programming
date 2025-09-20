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
    
    ll a,b; cin>>a>>b;
    if(a & 1) {
        if(b & 1) {
            a *= b;
            b = 1;
            cout << a + b;
        } else {
            while(b / 2 % 2 == 0) {
                a *= 2;
                b /= 2;
            }
            a *= b / 2;
            b = 2;
            if((a+b) % 2 == 1) {
                cout << -1;
            } else {
                cout << a + b;
            }
        }
        cout << nl;
        return;
    }

    // a is even
    // b must be even
    if(b & 1) {
        cout << -1 << nl;
        return;
    }
    while(b / 2 % 2 == 0) {
        a *= 2;
        b /= 2;
    }
    a *= b / 2;
    b = 2;
    cout << a + b << nl;
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

