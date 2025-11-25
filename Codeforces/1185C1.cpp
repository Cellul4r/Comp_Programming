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
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
struct BIT {

    vector<int> bit;

    void init(int n) {
        bit.resize(n+1);
    }

    void update(int idx, int val) {
        for(; idx < (int)bit.size(); idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    int sum(int i) {
        int res = 0;
        for(; i > 0; i -= i & -i) {
            res += bit[i];
        }
        return res;
    }

}sum, seen;
void solve(){
    
    int n,m; cin>>n>>m;
    vector<int> a(n+1);
    sum.init(n), seen.init(n);

    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    vector<int> ord(n);
    iota(all(ord), 1);
    sort(all(ord), [&](int i, int j) {
                return ord[i] > ord[j];
            });
    vector<int> idx(n+1);
    for(int i = 0; i < n; i++) {
        idx[ord[i]] = i + 1;
    }

    ll s = 0;
    for(int i = 0; i < n; i++) {
        s += a[i];
        int l = 0, r = n;    
        while(l <= r) {
            
        }
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

