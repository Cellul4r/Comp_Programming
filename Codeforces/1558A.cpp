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
    
    int a,b;
    cin>>a>>b;
    // 2 cases
    // 1 : A serve first
    // then pattern will be A B A B A B ...
    // 2 : B serve first 
    // B A B A B A B ...
    set<int> ans;
    int n = a + b;
    // a = x + (n + 1) / 2 - y
    // b = y + n / 2 - x
    // x = a - (n+1/2 - y)
    for(int y = 0; y <= (n+1) / 2; y++) {
        int x = a - ((n + 1) / 2 - y);
        if(x < 0 || x > n / 2) continue;
        ans.insert(x+y);
    }
    for(int y = 0; y <= n / 2; y++) {
        int x = a - (n / 2 - y);
        if(x < 0 || x > (n+1) / 2) continue;
        ans.insert(x+y);
    }
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x << " ";
    }
    cout << nl;
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

