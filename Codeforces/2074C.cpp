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

bool check(int x, int y) {
    int k = x ^ y;
    return (x + y > k && x + k > y && y + k > x);
}
void solve(){
    
    int x;
    cin>>x;
    int lg = 0;
    while((1 << lg) < x) lg++;
    if((1 << lg) == x || (1 << lg) - 1 == x) {
        cout << -1 << nl;
        return;
    }
    // test with 3
    if(check(x,3)) {
        cout << 3 << nl;
        return;
    }
    // test with 5
    if(check(x,5)) {
        cout << 5 << nl;
        return;
    }
    // test with 9
    if(check(x,9)) {
        cout << 9 << nl;
        return;
    }
    if(check(x,x-1)) {
        cout << x-1 << nl;
        return;
    }
    if(check(x,x/2+!(x%2))) {
        cout << x/2 + !(x%2) << nl;
        return;
    }
    cout << x << "FAILED" << nl;
    for(int y = 1; y < x; y++) {
        int k = x ^ y;
        if(x + y > k && x + k > y && y + k > x) {
            cerr << y << " ";
        }
    }
    assert(false);
    //cout << nl;
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

