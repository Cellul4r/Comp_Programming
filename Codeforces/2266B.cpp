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
    
    // if A >= B -> alice take all third pile stones to maxiize final score!
    // ans = A + C - B
    // if A < B?
    // ans = min(B - A, A + C - B)
    ll ans;
    ll a,b,c; cin>>a>>b>>c;
    if(a >= b) {
        ans = a + c - b;
    } else {
        ans = max(b - a, a + c - b);
    }
    cout << ans << nl;
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

