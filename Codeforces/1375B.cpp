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
const int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
void solve(){
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    bool ok = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>a[i][j];
            if(a[i][j] > 4) ok = false;
            if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if(a[i][j] > 3) ok = false;
            }
        }
    }
    if(a[0][0] > 2) ok = false;
    if(a[0][m-1] > 2) ok = false;
    if(a[n-1][0] > 2) ok = false;
    if(a[n-1][m-1] > 2) ok = false;
    if(!ok) {
        cout << "NO\n";
        return;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int now = 0;
            for(int l = 0; l < 4; l++) {
                int ni = i + dr[l], nj = j + dc[l];
                if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
                now++;
            }
            a[i][j] = now;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(a[i][j] > 4) ok = false;
            if(i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if(a[i][j] > 3) ok = false;
            }
        }
    }
    if(a[0][0] > 2) ok = false;
    if(a[0][m-1] > 2) ok = false;
    if(a[n-1][0] > 2) ok = false;
    if(a[n-1][m-1] > 2) ok = false;
    if(!ok) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << nl;
    }
    //cout << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

