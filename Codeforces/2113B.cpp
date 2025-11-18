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
    
    int w,h,a,b;
    int x1,y1,x2,y2;
    cin>>w>>h>>a>>b>>x1>>y1>>x2>>y2;

    if(x1 == x2) {
        cout << ((abs(y1 - y2) % b == 0) ? "YES" : "NO") << nl;
        return;
    }

    if(y1 == y2) {
        cout << ((abs(x1 -x2) % a == 0) ? "YES" : "NO") << nl;
        return;
    }

    cout << ((abs(x1-x2) % a == 0 || abs(y1-y2) % b == 0) ? "YES" : "NO") << nl;
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

