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
#define mp make_pair
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int n;
vector<pi> a[2];
map<pair<int,ll>,ll> dp;
ll recur(int i, ll l, ll r) {
    if(i == n) {
        //cerr << l << " CHECK " << r << nl;
        return l+r;
    }
    if(dp.find(mp(i,l+r)) != dp.end()) return dp[mp(i,l+r)];
    //cerr << i << " " << l << " " << r << nl;
    ll nl,nr; 
    if(a[0][i].first == 0) {
        nl = a[0][i].second;
    } else {
        nl = l * (a[0][i].second - 1);
    }
    if(a[1][i].first == 0) {
        nr = a[1][i].second;
    } else {
        nr = r * (a[1][i].second - 1);
    }

    ll ans = l+r;
    ans = max(ans, recur(i+1, l, r + nl + nr));
    ans = max(ans, recur(i+1, l + nl + nr, r));
    /*(for(ll k = 0; k <= nl + nr; k++) {
        ans = max(ans, recur(i+1, l + k, r + nl + nr - k));
    }*/
    return dp[mp(i,l+r)] = ans;
}
void solve(){
    
    cin>>n;
    a[0].resize(n);
    a[1].resize(n);
    for(int i=0;i<n;i++) {
        int x;
        char op;
        cin>>op>>x;
        a[0][i] = make_pair(op == '+' ? 0 : 1, x);
        cin>>op>>x;
        a[1][i] = make_pair(op == '+' ? 0 : 1, x);
    }
    
    ll ans = 0;
    ans += recur(0,1,1);
    cout << ans << nl;
    dp.clear();
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

