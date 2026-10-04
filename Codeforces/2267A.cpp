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
    
    int n;
    char c; cin>>n>>c;
    int ans = 0;
    string s; cin>>s;
    int l = 0, r = n - 1;
    while(l < r) {
        if(s[l] != s[r]) {
            // need to change to character c
            if(s[l] != c) {
                ans++;
            }
            if(s[r] != c) {
                ans++;
            }
        }
        l++;
        r--;
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

