/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =46;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
ll fib[N];
void solve(){
    
    int n; cin>>n;
    ll x,y; cin>>x>>y;
    // x,y<= 2^44
    
    for(int i = n; i >= 1; i--) {
        if(y > fib[i]) {
            y -= fib[i];
        }
        swap(x,y);
    }
    if(x == 1 && y == 1) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    fib[0] = fib[1] = 1;
    for(int i = 2; i < N; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

