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
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> mxR(n,0), mxC(m,0);
    int mx = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>a[i][j];
            mx = max(mx, a[i][j]);
        }
    }

    int now = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mxR[i] += (a[i][j] == mx);
            mxC[j] += (a[i][j] == mx);
            now += (a[i][j] == mx);
        }
    }

    int ans = mx;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int cnt = mxR[i] + mxC[j] - (a[i][j] == mx);
            if(cnt == now) {
                ans = mx - 1;
            }
        }
    }

    cout << ans << nl;
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

