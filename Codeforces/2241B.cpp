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
bool good(ll x) {
    ll tmp = x;
    set<int> save;
    while(tmp > 0) {
        save.insert(tmp % 10);
        tmp /= 10;
    }
    return save.size() <= 2;
}
void test(ll x) {
    
    for(ll y = 2; y <= 100; y++) {
        if(good(y)) {
            if(good(x*y)) {
                cout << y << " " << x * y << nl;
            }
        }
    }
}
void solve(){
    
    ll x; cin>>x;
    /*
    for(ll x = 1; x <= 100; x++) {
        cout << "TEST: " << x << nl;
        test(x);
    }
    */
    int cnt = 0;
    ll tmp = x, cur = 1;
    while(tmp > 0) {
        cnt++;
        cur *= 10ll;
        tmp /= 10;
    }
    cout << cur + 1 << nl;
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

