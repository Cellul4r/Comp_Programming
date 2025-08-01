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
bool reachable(array<int,3> a, array<int,3> b) {
    return 1ll * (a[0] - b[0]) * (a[0] - b[0]) >= 1ll * (a[1] - b[1]) * (a[1] - b[1]) + 1ll * (a[2] - b[2]) * (a[2] - b[2]);
}
void solve(){

    int g,n;
    cin>>g>>n;
    vector<array<int,3>> a(g);
    for(int i = 0; i < g; i++) {
        cin>>a[i][1] >> a[i][2] >> a[i][0];
    }
    sort(all(a));
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x,y,t;
        cin>>x>>y>>t;

        array<int,3> k = {t,x,y};
        int idx = upper_bound(all(a), k) - a.begin();
        cerr << idx << nl;
        if(idx < n && !reachable(k, a[idx])) {
            ans++; 
        } else if(idx > 0 && !reachable(k, a[idx-1])) {
            ans++;
        }
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

