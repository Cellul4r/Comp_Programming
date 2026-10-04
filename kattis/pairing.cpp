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
    
    int a,b,c,d; cin>>a>>b>>c>>d;

    // this is correct claim to match among themself first
    a %= 2;
    c %= 2;
    int ans = 0;
    int k = min(b,d);
    b -= k;
    d -= k;
    
    
    // try to match a to b
    // try to match c to d
    k = min(a,b);
    ans += k; 
    a -= k;
    b -= k;
    k = min(c,d);
    ans += k;
    c -= k;
    d -= k; 
    
    // try to match a to d
    // try to match c to b
    k = min(a,d);
    ans += k;
    a -= k;
    d -= k;
    k = min(c,b);
    ans += k;
    c -= k;
    b -= k;
    // try to match a to c
    ans += a + b + c + d;
    cout << ans;
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

