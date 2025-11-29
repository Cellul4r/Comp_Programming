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
    vector<int> a(k);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        x %= k;
        a[x]++;
    }
    
    int ans = a[0] / 2;
    int l = 1, r = k - 1;
    while(l < r) {
        ans += min(a[l],a[r]);
        l++;
        r--;
    }
    if(l == r) {
        ans += a[l] / 2;
    }
    cout << 2 * ans << nl;
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

