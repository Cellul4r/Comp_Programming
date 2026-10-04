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
void solve(){
    
    int n; cin>>n;
    // 1*p1 
    // 1 must not be in index 1
    // n = 2, 2 1
    // n = 4, 2 3 4 1, +-2, +-6, +-12 +-4
    // n = 6, 2 3 4 5 6 1, +-2, +-6, +-12, +-20, +-36, +-4
    for(int i = 2; i <= n; i++) {
        cout << i << " ";
    }
    cout << 1 << nl;
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

