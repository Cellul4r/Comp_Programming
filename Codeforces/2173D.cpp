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
vector<array<int,2>> a;
int m;
int dp[40][40][40];
int recur(int i, int cur, int k) {
    if(i == m) {
        if(k == 1) {
            return cur;
        } else {
            return 0;
        }
    }
    if(dp[i][cur][k] != -1) return dp[i][cur][k];
    //cerr << i << " " << cur << " " << k << nl;
    int ans = 0, one = a[i][0]; 
    // not merge with this one
    ans = max(ans, recur(i+1, one, k));
    int check = (cur == 0 ? 0 : 1);
    if(k - check >= 0) ans = max(ans, cur + recur(i+1, one, k - check));
    // merge with this group only if k >= op
    int op = (i > 0 ? a[i-1][1] : 0);
    if(k >= op) {
        check = (cur+op+one == 0 ? 0 : 1);
        if(k - check >= op) ans = max(ans, cur + one + op + recur(i+1, 0, k - op - check));
        ans = max(ans, recur(i+1, cur + one + op, k - op));
    }
    return dp[i][cur][k] = ans;
}
void solve(){
    
    ll n,k;
    cin>>n>>k;
    // if k >= 30 we can make all bit from 0 -> 29 (1)!
    // now if k < 30?
    if(k >= 30) {
        cout << k << nl;
        return;
    }
    a.clear();
    int one = 0, op = 0;
    for(int i = 0; i < 30; i++) {
        if((1 << i) & n) {
            if(op != 0) {
                // found new group
                a.push_back({one,op});
                one = 1;
                op = 0;
            } else {
                one++;
            }
        } else {
            op++;
        }
    }
    a.push_back({one,op});
    m = a.size();
    /*for(auto &x : a) {
        cout << x[0] << " " << x[1] << nl;
    }*/
    for(int i = 0; i < 40; i++) {
        for(int j = 0; j < 40; j++) {
            for(int l = 0; l < 40; l++) {
                dp[i][j][l] = -1;
            }
        }
    }
    int ans = recur(0,0,k);
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

