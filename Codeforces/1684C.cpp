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

void solve(){
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>a[i][j];
        }
    }
    
    int l=-1,r=-1;
    bool found = false;
    vector<int> bad;
    for(int i = 0; i < n && bad.empty(); i++) {
        vector<int> b = a[i];
        sort(all(b));
        for(int j = 0; j < m; j++) {
            if(a[i][j] != b[j]) {
                bad.push_back(j);
            }
        }
    }
    if(bad.empty()) {
        cout << 1 << " " << 1 << nl;
        return;
    }

    l = bad[0], r = bad[1];
    for(int i = 0; i < n; i++) {
        swap(a[i][l], a[i][r]);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m-1; j++) {
            if(a[i][j] > a[i][j+1]) {
                cout << -1 << nl;
                return;
            }

        }
    }

    cout << l+1 << " " << r+1 << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

