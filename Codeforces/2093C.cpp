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

void solve(){
    
    ll x,k;
    cin>>x>>k;
    if(x == 1) {
        cout << (k == 2 ? "YES" : "NO") << nl;
        return;
    }
    bool isPrime = true;
    for(ll i = 2; i * i <= x; i++) {
        if(x % i == 0) {
            isPrime = false;
        }
    }
    if(isPrime && k == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

