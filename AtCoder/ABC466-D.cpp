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
    vector<bool> a(n+1), b(n+1);
    vector<array<int,2>> save;
    for(int i = 1; i <= m; i++) {
        int r, c; cin>>r>>c;
        save.push_back({r,c});
    }
    reverse(all(save));
    ll ans = 0;
    for(auto &x : save) {
        int r = x[0], c = x[1];
        if(a[r] || b[c]) {
            a[r] = true;
            b[c] = true;
            continue;
        }
        a[r] = true;
        b[c] = true;
        ans++;
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

