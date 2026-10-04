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
    
    int a,b,c; cin>>a>>b>>c;
    int ans = 0;
    while(a != b && a != c && b != c) {
        ans++;
        int mx = max({a,b,c}), mn = min({a,b,c});
        int aa = a, bb = b, cc = c;
        if(mx == a) {
            aa--;
        } else if(mx == b) {
            bb--;
        } else {
            cc--;
        }
        if(mn == a) {
            aa++;
        } else if(mn == b) {
            bb++;
        } else {
            cc++;
        }
        a = aa;
        b = bb;
        c = cc;
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

