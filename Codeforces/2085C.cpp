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
    
    ll x,y;
    cin>>x>>y;
    if(x == y) {
        cout << -1 << nl;
        return;
    }
    if(!(x & y)) {
        cout << 0 << nl;
        return;
    }
    if(x > y) swap(x,y);

    ll k = 0;
    for(int i = 0; i < 32; i++) {
        if((y+k) & (1ll << i)) {
            k |= (1ll << i);
        }
    }
    assert(!((x + k) & (y + k)));
    cout << k << nl;
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

