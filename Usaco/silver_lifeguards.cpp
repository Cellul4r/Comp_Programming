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
void solve() {
    
    int n;
    cin>>n;
    vector<pi> a(n);
    for(auto &x : a) {
        cin>>x.first>>x.second;
    }
    sort(all(a));
    int l = 0, r = 0;
    int total = 0;

    for(int i = 0; i < n; i++) {
        if(a[i].second > r) {
            l = max(r, a[i].first);
            total += a[i].second - l;
            r = a[i].second;
        }
    }

    int ans = 0;
    a.push_back(make_pair(a[n-1].second,a[n-1].second+1));
    // interval time that cow i is alone
    l = 0, r = 0;
    for(int i = 0; i < n; i++) {
        l = max(a[i].first,r);
        int rAlone = min(a[i+1].first, a[i].second);
        ans = max(ans, total - max(0,(rAlone - l)));
        r = max(r, a[i].second);
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    setIO("lifeguards");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

