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
    string s; cin>>s;
    // suppose we delete d0 0's and d1 1's character
    // zero, one
    // abs(d0 - d1) <= 1
    int zero = 0, one = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            zero++;
        } else {
            one++;
        }
    }
    int ga = 0, gb = 0;
    char c = s[0];
    for(int i = 1; i < n; i++) {
        if(c == s[i]) {
            continue;
        } else if(c == '0'){
            ga++;
        } else {
            gb++;
        }
        c = s[i];
    }
    if(c == '0') ga++;
    else gb++;

    int mx = -1;
    for(int d = -1; d <= 1; d++) {
        if(abs(zero - one - d) > 1) continue;

        int now;
        if(d == -1) {
            now = max(2 * gb - 1,0); 
        } else if(d == 0) {
            now = 2 * min(ga, gb);
        } else {
            now = max(2 * ga - 1,0);
        }
        mx = max(mx, now);
    }
    if(mx == -1) {
        cout << -1 << nl;
        return;
    }
    cout << n - mx << nl;
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

