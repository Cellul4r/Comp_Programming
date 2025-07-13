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
int dist(int i, int j, int x, int y) {
    return abs(i - x) + abs(j - y);
}
void solve(){
    
    int n,m;
    cin>>n>>m;
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int k = 0;
            k = max(k, dist(i,j, 1,1)); 
            k = max(k, dist(i,j, 1,m));
            k = max(k, dist(i,j, n,1));
            k = max(k, dist(i,j, n,m));
            ans.push_back(k);
        }
    }

    sort(all(ans));
    for(int i = 0; i <= n * m - 1; i++) {
        cout << ans[i] << " ";
    }
    cout << nl;
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

