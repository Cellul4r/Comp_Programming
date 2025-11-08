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

void test(int x) {

    string ax = to_string(x);
    cerr << "TEST: " << x << nl;
    for(int j = 1; j < 1e6; j++) {
        string ay = to_string(j);
        string k = ax + ay;
        ll now = stoll(k);
        if(now % (x + j) == 0) {
            cerr << j << " : " << k << nl;
        }
    }
}
void solve(){

    int x;
    cin>>x;
    //test(x);
    cout << 2 * x << nl;
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

