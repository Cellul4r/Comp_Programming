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
    
    ll n;
    cin>>n;
    if(n <= 6) {
        cout << "NO" << nl;
        return;
    }
    for(ll k = 2; k < 1000; k++) {
        ll now = 1 + k;
        ll x = k * k;
        for(int i = 2; i < 32; i++) {
            now += x;
            if(now > 1e6) break;
            if(now == n) {
                cout << "YES\n";
                return;
            }
            x *= k;
        }
    }

    cout << "NO\n";
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

