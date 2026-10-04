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
    
    int n,m; cin>>n>>m;
    vector<vector<ll>> a(n,vector<ll>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>a[i][j];
        }
    }
    ll ans = 0;
    int i = 0, i1 = n - 1;
    while(i <= i1) {
        vector<ll> cur;
        int j = 0, j1 = m-1;
        while(j <= j1) {
            cur.push_back(a[i][j]);
            if(i1 != i) {
                cur.push_back(a[i1][j]);
            }
            if(j1 != j) {
                cur.push_back(a[i][j1]);
            }
            if(i1 != i && j1 != j) {
                cur.push_back(a[i1][j1]);
            }
            j++;
            j1--;
        } 
        sort(all(cur));
        ll sum = cur[cur.size() / 2];
        for(auto &x : cur) {
            ans += abs(sum - x);
        }
        i++;
        i1--;
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

