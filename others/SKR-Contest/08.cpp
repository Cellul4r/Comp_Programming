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
const int N =1e6+1;
const int INF = 10000007;
const ll LINF = 1e18+7;

void addM(int& a, int b) {
    a += b;
    if(a >= INF) a -= INF;
}
int dp[N];
int recur(int i, int n) {
    if(i == n) {
        return 1;
    }
    if(~dp[i]) return dp[i];
    int ans = 0;
    // try to put zero '0'
    //cerr << i << nl;
    addM(ans, 3 * recur(i+1, n) % INF);
    // try to put one and two : '1', '2'
    // 1(0,2)(0,2)(0,1,2)
    // 2(0,1)(0,1)(0,1,2)
    if(i < n - 2) {
        addM(ans, (8 * recur(i + 3, n) % INF));
    } else if(i < n - 1) {
        addM(ans, (4 * recur(i + 2, n) % INF));
    }
    return dp[i] = ans;
}
void solve(){
    
    int n;
    cin>>n;
    memset(dp, -1, sizeof dp);
    int ans = recur(0,n) % INF;
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

