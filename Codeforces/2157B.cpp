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
    
    ll n,x,y; cin>>n>>x>>y;
    string s; cin>>s;
    x = abs(x);
    y = abs(y);
    ll a = 0, b = 0;
    for(auto &k : s) {
        if(k == '4') a++;
        else b++;
    }
    ll xx = b, yy = b;
    while(a) {
        a--;
        if(xx < x) xx++;
        else if(yy < y) yy++;
    }

    if(xx >= x && yy >= y) {
        cout << "YES" << nl;
        return;
    }

    cout << "NO" << nl;
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

