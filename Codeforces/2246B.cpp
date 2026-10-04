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
    
    // n = 1 -> 1
    // n = 2 -> -1
    // n = 3 -> 1 2 3
    // n = 4 -> 1 2 3 6
    // n = 5 -> 1 2 3 6 
    // n = 6 -> 1 2 3 6 12 24
    // n = 7 -> 1 2 3 6 12 24 48
    // (S / a[i]) = 1 + (S - a[i]) / a[i]
    int n; cin>>n;
    if(n == 1) {
        cout << 1 << nl;
        return;
    }
    if(n == 2) {
        cout << -1 << nl;
        return;
    }
    ll cur = 6;
    cout << 1 << " " << 2 << " " << 3 << " ";
    for(int i = 4; i <= n; i++) {
        cout << cur << " ";
        cur += cur;
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

