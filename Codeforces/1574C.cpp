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
    
    int n,m;
    cin>>n;
    vector<ll> a(n);
    ll sum = 0;
    for(auto &x : a) {
        cin>>x;
        sum += x;
    }
    cin>>m;
    sort(all(a)); 
    cerr << sum << nl;
    for(int i = 0; i < m; i++) {
        ll x,y;
        cin>>x>>y;
        auto it = lower_bound(all(a), x);
        ll ans1 = 0, ans2 = 0;
        ll s = sum;
        if(it != a.end()) {
            s -= *it;
        } else {
            s -= a[n-1];
            ans1 += x - a[n-1];
        }
        ans1 += max(0ll, y - s);
        s = sum;
        if(it != a.begin()) {
            ans2 += x - *(it-1);
            s -= *(it-1);
            ans2 += max(0ll, y - s);
        } else {
            ans2 = LINF;
        }
        cout << min(ans1,ans2) << nl;
    }
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

