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

void solve(){
    
    int n,x,y;
    cin>>n>>x>>y;
    assert(n <= 3000 && x >= y);
    string a,b;
    cin>>a>>b;
    vector<int> idx;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) idx.push_back(i);
    }
    if((int)idx.size() & 1) {
        cout << -1 << nl;
        return;
    }
    ll ans = 0;
    int k = idx.size();
    for(int i = 0; i < k / 2; i++) {
        int l = idx[i], r = idx[i + k / 2]; 
        if(l+1 == r) {
            ans += min(x, 2*y);
        } else {
            ans += y;
        }
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

