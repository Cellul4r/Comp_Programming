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
const int N = 9;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n,m;
int recur(int i, int j, vector<vector<int>>& a) {
    if(i >= n) {
        bool ok = true;
        for(int k = 0; k < n; k++) {
            int deg = 0;
            for(int l = 0; l < n; l++) {
                if(a[k][l]) {
                    deg++;
                }
            }
            if(deg != 2) {
                ok = false;
                break;
            }
        }
        return (ok ? 0 : INF);
    }
    cerr << i << " " << j << nl;
    int ans = INF;
    int ni = i, nj = j + 1;
    if(nj == n) {
        ni++;
        nj = 0;
    }
    // do nothing
    ans = min(ans, recur(ni,nj,a));
    if(a[i][j]) {
        // remove or not?
        a[i][j] = 0;
        a[j][i] = 0;
        ans = min(ans, 1 + recur(ni, nj, a));
        a[i][j] = 1;
        a[j][i] = 1;
    } else {
        // add or not?
        a[i][j] = 1;
        a[j][i] = 1;
        ans = min(ans, 1 + recur(ni, nj, a));
        a[i][j] = 0;
        a[j][i] = 0;
    }
    return ans;
}
void solve(){
    
    cin>>n>>m; 
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < m; i++) {
        int u,v;
        cin>>u>>v;
        u--,v--;
        a[u][v] = 1;
        a[v][u] = 1;
    }
    cout << recur(0,0,a);
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

