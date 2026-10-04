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
    
    int n,m,h; cin>>n>>m>>h;
    vector<vector<int>> ans(n+1,vector<int>(m+1));
    vector<int> f(m+1), l(n+1);

    for(int i = 1; i <= m; i++) {
        cin>>f[i];
    }

    for(int i = 1; i <= n; i++) {
        cin>>l[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin>>ans[i][j];
        }
    }

    for(int i = 1; i <= m; i++) {
        if(f[i] == 0) continue;
        for(int j = 1; j <= n; j++) {
            if(ans[j][i] == 0) continue;
            ans[j][i] = min(f[i], l[j]);
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << ans[i][j] << " ";
        }
        cout << nl;
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

