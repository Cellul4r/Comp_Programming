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
    
    int n,m,r;
    cin>>n>>m>>r;
    
    vector<int> cows(n);
    vector<ll> rents(r);
    vector<pi> milks(m);
    for(auto &x : cows) {
        cin>>x;
    }
    for(auto &x : milks) {
        cin>>x.first>>x.second;
    }
    for(auto &x : rents) {
        cin>>x;
    }
    sort(all(cows), greater<int>());
    sort(all(milks), [](pi i, pi j) {
                return i.second > j.second;
            });
    sort(all(rents), greater<ll>());
    rents.insert(rents.begin(),0);
    int j = 0;
    for(int i = 1; i <= r; i++) {
        rents[i] += rents[i-1];
    }
    ll ans = rents[min(n,r)];
    ll cur = 0;
    ll now = 0;
    for(int i = 0; i < n; i++) {
        cur += cows[i];
        while(j < m && cur > 0) {
            ll k = min(cur, 1ll * milks[j].first);
            cur -= k;
            milks[j].first -= k;
            now += 1ll * milks[j].second * k;
            if(milks[j].first == 0) {
                j++;
            }
        }
        ans = max(ans, now + rents[min(r,n-i-1)]);
        //cerr << i << " " << now << " " << rents[min(r-1,n-i-2)] << " " << ans << nl;
    }

    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    setIO("rental");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

