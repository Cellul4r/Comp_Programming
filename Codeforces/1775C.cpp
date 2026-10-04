/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    // clearly if n is odd and x is odd -> n == x else -1
    ll n,x; cin>>n>>x;
    ll mn = 0;
    auto f = [&](ll x, int i) {
        if((1ll<<i)&x) return 1;
        return 0;
    };
    ll cur = 0;
    for(int i = 0; i < 60; i++) {
        int a = f(n,i), b = f(x,i);
        if(a == 0 && b == 1) {
            cout << -1 << nl;
            return;
        }
        
        // a = 1, b = 0
        // this formula is has not correct yet
        if(a == 1 && b == 0) {
            mn = max(mn, (1ll<<i)-cur);
        }
        if(a) {
            cur += (1ll << i);
        }
    }
    // do the operation to make it greate and make >= mn 
    // the operation can make in range [1<<mn,1<<(mn+1) )
    for(int i = 0; i < 60; i++) {
        int a = f(n,i), b = f(x,i);
        if(a == 1 && b == 1) {
            // the n + (1<<mn) shouldn't make bit i of a to zero
            if(f(n+mn,i) == 0) {
                cout << -1 << nl;
                return;
            }
        }
    }
    cout << n + mn << nl;
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

