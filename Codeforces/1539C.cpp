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
    ll k,x;
    cin>>n>>k>>x;
    vector<ll> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    sort(all(a));
    vector<ll> groups;
    for(int i = 1; i < n; i++) {
        if(a[i] - a[i-1] > x) {
            ll now = max(0ll, (a[i] - a[i-1] + x - 1) / x - 1);
            //cerr << now << nl;
            groups.push_back(now);
        }
    }
    sort(all(groups));
    int i = 0;
    int ans = groups.size() + 1;
    while(i < (int)groups.size() && k >= groups[i]) {
        k -= groups[i];
        ans--;
        i++;
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

