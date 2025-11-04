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
int n;
ll a[N];
ll sum = 0;
map<int,ll> cnt;
ll recur(ll cur, int alice) {
    if(cur == 0) {
        return 0ll;
    }

    ll ans = LINF;
    ll now = 0; 
    for(auto &[x,y] : cnt) {
        if(y == 0) continue;
        if(x == 0) continue;
        ll k = y;
        cnt[x] -= k;
        cnt[x-1] += k;
        now = max(now, (alice ? k : 0) + recur(cur - k, alice^1));
    }
    ans = min(ans, now);
    return ans;
}
void solve(){
    
    cin>>n;
    sum = 0;
    cnt.clear();
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        sum += a[i];
        cnt[a[i]]++;
    }

    ll alice = recur(sum, 1);
    cout << alice << " " << sum - alice << nl;
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

