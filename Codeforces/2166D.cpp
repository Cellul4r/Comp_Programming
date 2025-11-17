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
const int N =5005;
const ll INF = 998244353;
const ll LINF = 998244353;

void setIO(string);
int n;
ll cnt[N];
ll recur(int i, ll now) {
    if(i == n+1 && now <= n) {
        return 1ll;
    }
    if(i == n+1) {
        return 0ll;
    }

    ll ans = 0;
    for(int j = 0; j <= cnt[i]; j++) {
        ans = (ans + recur(i+1, now+(cnt[i]-j))) % INF;
    }
    cerr << i << " CHECK " << now << " : " << ans << nl;
    return ans;
}
void solve(){
    
    cin>>n;
    for(int i = 1; i <= n; i++) cnt[i] = 0;

    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        cnt[x]++;
    }

    ll ans = recur(1,0);
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

