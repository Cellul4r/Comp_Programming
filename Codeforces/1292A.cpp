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
const int dr[] = {-1,-1,1,1,1,-1}, dc[] = {0,1,1,0,-1,-1};
void solve(){
    
    int n,q; cin>>n>>q;
    vector<vector<bool>> a(2, vector<bool>(n));
    int bad = 0;
    for(int i = 1; i <= q; i++) {
        int r,c; cin>>r>>c; 
        r--,c--;
        int x = (a[r][c] ? -1 : 1);
        for(int k = 0; k < 6; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if(nr < 0 || nc < 0 || nr >= 2 || nc >= n) continue;
            if(a[nr][nc]) {
                bad += x;
            }
        }
        a[r][c] = !a[r][c];
        //cout << bad << nl;
        //assert(bad >= 0);
        cout << (bad > 0 || a[0][0] || a[1][n-1] ? "NO" : "YES") << nl;
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

