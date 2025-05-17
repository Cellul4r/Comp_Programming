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
    
    ll x;
    cin>>x;
    if(x & 1) {
        cout << -1 << nl;
        return;
    }

    bool ok = true;
    for(int i = 0; i <= 32; i++) {
        if(((1 << i) & x) && (1 << (i+1) & x)) {
            ok = false;
            break;
        }
    }
    if(ok) {
        cout << x / 2 << " " << x + x / 2 << nl;
    } else {
        cout << -1 << nl;
    }
    /*for(ll i = 1; i <= 1000; i++) {
        for(ll j = 1; j <= 1000; j++) {
            if((i ^ j) == x && (i + j) == 2 * x) {
                cerr << i << " " << j << " " << (i ^ j) << nl;
            }
        }
    }*/
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

