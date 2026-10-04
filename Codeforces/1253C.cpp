/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n,m; cin>>n>>m; 
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    sort(all(a));
    ll ans = 0;
    int cur = 0;
    vector<ll> sum(m, 0);
    for(int i = 0; i < n; i++) {
        ans += a[i];
        if(i >= m) {
            sum[cur % m] += a[cur];
            ans += sum[cur % m];
            cur++;
        }
        cout << ans << " ";
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

