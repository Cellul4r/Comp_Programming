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
    
    int n;
    ll k;
    cin>>n>>k;
    vector<ll> a;
    for(int i = 0; i < n; i++) {
        ll x; cin>>x;
        if(x >= k) continue;
        a.push_back(x);
    }
    multiset<ll> cur;
    for(int i = 0; i < n; i++) {
        ll x; cin>>x;
        cur.insert(x);
    }
    sort(all(a));
    ll ans = 0;
    n = a.size();
    for(auto &r : a) {
        if(cur.empty()) break;
        ll now = (k - r) / (r + 1ll);
        auto it = cur.upper_bound(now);
        if(it == cur.begin()) {
            continue;
        }
        it--;
        cur.erase(it);
        ans++;
    }
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

