/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =256;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
ll ans[N][N];
void solve(){
    
    int n,m;
    cin>>n>>m;
    cout << n * m << nl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
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
    ll now = 0;
    for(int i = 0; i < N; i += 2) {
        for(int j = 0; j < N; j += 2) {
            ans[i][j] = now;
            ans[i][j+1] = now+1;
            ans[i+1][j] = now+2;
            ans[i+1][j+1] = now+3;

            now += 4;
        }
    }
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

