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
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> colorsX(1e5+1), colorsY(1e5+1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int x;
            cin>>x;
            colorsX[x].push_back(i);
            colorsY[x].push_back(j);
        }
    }

    ll ans = 0;
    for(int i = 1; i < 1e5+1; i++) {
        int k = colorsX[i].size();
        sort(all(colorsX[i]));
        sort(all(colorsY[i]));
        for(int l = 0, r = k - 1, mul = k - 1; l <= r; l++,r--, mul -= 2) {
            //cerr << i << " " << l << " " << r << nl;
            ans += -mul * 1ll * colorsX[i][l];
            if(l != r) {
                ans += mul * 1ll * colorsX[i][r];
            }
            //cerr << ans << nl;
        }
        k = colorsY[i].size();
        for(int l = 0, r = k - 1, mul = k - 1; l <= r; l++,r--, mul -= 2) {
            //cerr << i << " " << l << " " << r << nl;
            ans += -mul * 1ll * colorsY[i][l];
            if(l != r) {
                ans += mul * 1ll * colorsY[i][r];
            }
        }
        //if(i == 1) cerr << ans << nl;
    }
    cout << ans << nl;
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

