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
    for(int i = 0; i < n; i++) {
        string s;
        cin>>s;
        for(int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    if(a[0][0] == 1) {
        cout <<  -1 << nl;
        return;
    }
    vector<pair<pi,pi>> ans;
    for(int i = 0; i < n; i++) {
        for(int j = m - 1; j > 0; j--) {
            if(a[i][j] == 1) {
                ans.push_back({{i,j-1}, {i,j}});
            }
        }
    }
    
    for(int i = n-1; i > 0; i--) {
        if(a[i][0] == 1) {
            ans.push_back({{i-1,0}, {i,0}});
        }
    }
    cout << ans.size() << nl;
    for(auto &[x,y] : ans) {
        cout << x.first + 1 << " " << x.second + 1 << " " << y.first + 1 << " " << y.second + 1 << nl;
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

