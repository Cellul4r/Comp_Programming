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
#define sz(x) (int)(x.size())
const char nl = '\n';
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n; cin>>n;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    vector<deque<int>> cnt(n+1);
    vector<int> dp(n+1,0);
    
    for(int i = 1; i <= n; i++) {
        int x = a[i-1];
        if(sz(cnt[x]) == x) {
            cnt[x].pop_front();
            cnt[x].push_back(i);
            dp[i] = x + dp[cnt[x].front()-1];
        } else if(sz(cnt[x]) + 1 == x) {
            cnt[x].push_back(i);
            dp[i] = x + dp[cnt[x].front()-1];
        } else {
            cnt[x].push_back(i);
        }
        dp[i] = max(dp[i],dp[i-1]);
    }

    cout << dp[n] << nl;
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

