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
void solve(){
    
    int n,m; cin>>n>>m;
    string s,t; cin>>s>>t;

    vector<int> pre(m+1), suff(m+2, INF);// smallest position of t[i] in s where t can still be constructed from s
    int cur = 1;
    for(int i = 1; i <= m; i++) {
        while(s[cur-1] != t[i-1] || cur <= pre[i-1]) {
            cur++;
        }
        pre[i] = cur;
    }
    cur = n;
    for(int i = m; i >= 1; i--) {
        while(s[cur-1] != t[i-1] || cur >= suff[i+1]) {
            cur--;
        }
        suff[i] = cur;
    }

    int ans = 1;
    for(int i = 1; i < m; i++) {
        ans = max(ans, suff[i+1] - pre[i]);
    }
    cout << ans << nl;
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

