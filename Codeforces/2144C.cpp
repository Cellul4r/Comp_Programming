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
const int N =1e3+1;
const int INF = 1e9+7;
const ll LINF = 998244353; 

void setIO(string);
int n;
int a[N],b[N];
ll dp[N][2];
ll recur(int i, bool op) {
    if(i == n) {
        return 1ll;
    }

    if(dp[i][op] != -1) return dp[i][op];
    ll ans = 0;
    if(i == 0) {
        ans = (ans + recur(i+1, false)) % LINF;
        ans = (ans + recur(i+1, true)) % LINF;
    } else if(!op){
        if(a[i] >= a[i-1] && b[i] >= b[i-1]) {
            ans = (ans + recur(i+1, false)) % LINF;
        }
        if(b[i] >= a[i-1] && a[i] >= b[i-1]) {
            ans = (ans + recur(i+1, true)) % LINF;
        }
    } else {
        if(a[i] >= b[i-1] && b[i] >= a[i-1]) {
            ans = (ans + recur(i+1, false)) % LINF;
        }
        if(b[i] >= b[i-1] && a[i] >= a[i-1]) {
            ans = (ans + recur(i+1, true)) % LINF;
        }
    }
    return dp[i][op] = ans;
}
void solve(){
    
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0;j < 2; j++) {
            dp[i][j] = -1;
        }
        cin>>b[i];
    }

    cout << recur(0,false) << nl;
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

