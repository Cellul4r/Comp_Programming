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
int fib[12];
void solve(){
    
    int n,m;
    cin>>n>>m;
    string ans;
    for(int i = 0; i < m; i++) {
        int w,l,h;
        cin>>w>>l>>h;
        int k = max({w,l,h});
        int x = min({w,l,h});
        if(k >= fib[n-1] + fib[n] && x >= fib[n]) {
            ans += '1';
        } else {
            ans += '0';
        }
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    fib[1] = 1;
    fib[2] = 2;
    for(int i = 3; i <= 11; i++) {
        fib[i] = fib[i-1] + fib[i-2]; 
    }
    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

