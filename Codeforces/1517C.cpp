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
    
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(n));

    vector<int> p(n);
    for(auto &x : p) cin>>x;
    for(int i = n - 1; i >= 0; i--) {
        int& x = p[i];
        int cnt = p[i];
        int r = i, c = i; 
        while(cnt != 0) {
            cnt--;
            if(a[r][c] != 0) {
                cout << -1 << nl;
                return;
            }
            a[r][c] = x;
            if(r + 1 < n && a[r+1][c] == 0) {
                r++;
            } else {
                c--;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cout << a[i][j] << " ";
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

