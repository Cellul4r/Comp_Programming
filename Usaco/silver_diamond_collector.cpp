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
    for(auto &x : a) cin>>x;
    sort(all(a));
    vector<int> lessK(n);
    int l = 0, r = 0;
    while(l < n) {
        while(r < n && a[r] - a[l] <= k) {
            r++;
        }
        lessK[l] = r - l;
        l++;
    }
    vector<int> maxSuff(n+1);
    for(int i = n - 1; i >= 0; i--) {
        maxSuff[i] = max(maxSuff[i+1], lessK[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans,lessK[i] + maxSuff[i + lessK[i]]);
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    setIO("diamond");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

