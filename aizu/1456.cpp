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
ll a,b;
vector<ll> c;
ll check() {

    ll mn = LINF;
    int cur = 70;
    for(auto &x : c) {
        int now = 0;
        for(int i = 0; i < 64; i++) {
            if((1ll<<i) & x) {
                now++;
            }
        }
        if(now == cur) {
            mn = min(mn, x);
        } else if(now < cur) {
            mn = x;
            cur = now;
        }
    }
    return mn;
}
void test() {

    for(int x = 1; x <= 1000; x++) {
        int now = 0;
        for(int i = 0; i < 64; i++) {
            if((1ll<<i) & x) {
                now++;
            }
        }
        cerr << x << " " << now << nl;
    }
}
void solve(){
    
    cin>>a>>b;
    ll lg = 0;
    while((1ll<<lg)<a) lg++;
    lg = (1ll << lg);
    if(lg <= b) {
        cout << lg << nl;
        return;
    }

    // no power of 2 in range[a,b]
    // that means no number that has 1 bits
    // power of 2 < a has x bits
    // power of 2 > b has y bits = x + 1 bits
    ll cur = a;
    while(cur <= b) {
        c.push_back(cur);
        cur += (cur & -cur);
    }
    cout << check() << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();
    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

