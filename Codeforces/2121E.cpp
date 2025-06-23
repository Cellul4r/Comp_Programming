/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ld,ld> pd;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const int LOG = 20;
void setIO(string);

int n;
string l,r;
int ll[LOG], rr[LOG];
int dp[LOG][4];
int recur(int i, int type) {
    if(i == n) {
        return 0;
    }
    if(dp[i][type] != -1) return dp[i][type];
    //cerr << i << " " << type << nl;
    int ans = 1000000;
    int start = 0, end = 9;
    if(type == 0) {
        // we can use digit from 0 - 9
    } else if(type == 1) {
        // we must use digit >= digitL
        start = ll[i];
    } else if(type == 2) {
        // we must use digit <= digitR
        end = rr[i];
    } else {
        // we must use digitL <= d and d <= digitR
        start = ll[i];
        end = rr[i];
    }
    for(int j = start; j <= end; j++) {
        if(j == ll[i] && j == rr[i]) {
            ans = min(ans, 2 + recur(i + 1, 3));
        } else if(j == ll[i]) {
            ans = min(ans, 1 + recur(i + 1, 1));
        } else if(j == rr[i]) {
            ans = min(ans, 1 + recur(i + 1, 2));
        } else {
            ans = min(ans, recur(i + 1, 0));
        }
    }
    return dp[i][type] = ans;
}
void solve(){
    
    cin>>l>>r;
    // f(l,x) + f(r,x) minimum!
    n = l.length();     
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            dp[i][j] = -1;
        }
    }
    for(int i = 0; i < n; i++) {
        ll[i] = l[i] - '0';
    }
    for(int i = 0; i < n; i++) {
        rr[i] = r[i] - '0';
    }

    int ans = recur(0, 3);
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

