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
    
    int n; cin>>n;

    set<int> row1,row2;
    // row1 -> save not yet activated of cell on row1
    // row2 -> save not yet activated of cell on row2

    vector<vector<int>> a(2, vector<int>(n,0));
    vector<vector<pi>> save(2*n+1);
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) {
            cin>>a[i][j];
            save[a[i][j]].push_back({i,j});
        }
    }

    for(int i = 0; i < n; i++) {
        row1.insert(i);
        row2.insert(i);
    }

    row1.insert(INF);
    row2.insert(-INF);
    auto check = [&]() {
        if(row1.count(0)) return false; 
        if(row2.count(n-1)) return false;
        if(*row1.begin() - 1 <= *row2.rbegin()) return false;

        return true;
    };

    auto add = [&](int v) {
        for(auto &[i, j] : save[v]) {
            if(i == 0) {
                row1.erase(j);
            } else {
                row2.erase(j);
            }
        }
    };
    auto del = [&](int v) {
        for(auto &[i, j] : save[v]) {
            if(i == 0) {
                row1.insert(j);
            } else {
                row2.insert(j);
            }
        }
    };

    int r = 0;
    ll ans = 0;
    for(int l = 1; l <= 2 * n; l++) {
        while(r + 1 <= 2 * n && !check()) {
            add(++r); 
        }
        if(!check()) break;

        ans += 2ll * n - r + 1;
        del(l);
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

