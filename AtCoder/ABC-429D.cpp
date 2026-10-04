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
    
    ll n,m,c;
    cin>>n>>m>>c;
    map<ll,int> cnt;
    for(int i = 1; i <= n; i++) {
        ll x;
        cin>>x;
        cnt[x]++;
    }
    if(cnt.find(0) == cnt.end()) cnt[0] = 0;
    if(cnt.find(m-1) == cnt.end()) cnt[m-1] = 0;
    vector<ll> a,b;
    ll ans = 0;
    ll prv = -1;
    for(auto &[x,y] : cnt) {
        a.push_back(y);
        b.push_back(x - (prv == -1 ? x - 1 : prv));
        prv = x;
    }
    int k = a.size();
    for(int i = 0; i < k; i++) {
        a.push_back(a[i]);
    }
    k = a.size();
    for(int i = 1; i < k; i++) {
        a[i] += a[i-1];
    }
    for(int i = 0; i < k / 2; i++) {
        int idx = lower_bound(all(a), c + a[i]) - a.begin();
        assert(idx < k);
        ans += b[i] * (a[idx] - a[i]);
    }
    cout << ans;
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

