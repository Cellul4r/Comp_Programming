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
bool ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    string s; cin>>s;
    return s == "Yes";
}
void solve(){
    
    int n; cin>>n;
    ll ans = 0;
    int l = 1, r = 1;
    while(l < n) {
        if(l > r) r = l;
        while(r+1 <= n && ask(l, r+1)) {
            r++;
        }
        // d(l,r) <= 1
        // d(l+1,r), d(l+2,),... <= 1
        ll k = r - l;
        ans += k;
        l++;
    }
    cout << "! " << ans << endl;
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

