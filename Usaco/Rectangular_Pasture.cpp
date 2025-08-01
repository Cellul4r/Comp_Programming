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
const int N =2500+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);

int n;
int pre[N][N];
pi cows[N];

int sum2D(int x1, int y1, int x2, int y2) {
    return pre[x2][y2] - pre[x2][y1-1] - pre[x1-1][y2] + pre[x1-1][y1-1];
}
void solve(){
    
    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin>>cows[i].first >> cows[i].second;
    }
    sort(cows+1,cows+n+1);
    // x compression
    for(int i = 1; i <= n; i++) {
        cows[i].first = i;
    }
    sort(cows+1,cows+n+1, [&](pi i, pi j) {
                return i.second < j.second;
            });
    for(int i = 1; i <= n; i++) {
        cows[i].second = i;
    }

    // convert to order of coordinate x
    sort(cows+1,cows+n+1);
    for(int i = 1; i <= n; i++) {
        pre[cows[i].first][cows[i].second] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
        }
    }

    ll ans = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int top = min(cows[i].second,cows[j].second); 
            int bottom = max(cows[i].second, cows[j].second);
            ans += 1ll * sum2D(i,1,j,top) * sum2D(i,bottom,j,n);
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

