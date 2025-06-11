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
    
    int n,k;
    cin>>n>>k;

    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    auto f = [&](int x) {
        // answer at least x
        vector<int> pre(n);
        for(int i = 0; i < n; i++) {
            pre[i] = (a[i] < x ? -1 : 1);
        }
        for(int i = 1; i < n; i++) pre[i] += pre[i-1];
        int mn = 0, mx = pre[k-1];
        for(int i = k; i < n; i++) {
            mn = min(mn, pre[i-k]);
            mx = max(mx, pre[i] - mn);
        }

        return mx > 0;
    };
    int l = 1, r = n;
    while(l < r) {
        int mid = l + (r - l + 1) / 2;
        if(f(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l;
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

