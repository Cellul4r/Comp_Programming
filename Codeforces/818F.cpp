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
    cin>>n;

    auto f = [&](ll edges) {
        int bridges = (edges + 1) / 2;
        
        int remainEdges = edges - bridges;
        ll cycleEdges = 1ll * (n - bridges) * (n - bridges - 1) / 2ll;
        return remainEdges <= cycleEdges; 
    };

    ll l = n - 1, r = 2ll * n - 2;
    while(l < r) {
        ll mid = l + (r - l + 1) / 2;
        if(f(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << l << nl;
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

