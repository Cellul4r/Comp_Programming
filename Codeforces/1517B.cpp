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

    vector<array<ll,3>> a;
    ll check[n][m];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x; cin>>x;
            a.push_back({x,i,j});
            check[i][j] = x;
        }
    }
    sort(all(a));
    // assign each person to some least tiredness in non-decreasing order
    vector<vector<int>> ans(n, vector<int>(m,-1));
    for(int j = 0; j < m; j++) {
        ans[a[j][1]][j] = a[j][0];
    }

    for(int j = 0; j < n; j++) {
        multiset<int> save;
        for(int i = 0; i < m; i++) save.insert(check[j][i]);
        for(int i = 0; i < m; i++) {
            if(ans[j][i] == -1) continue;
            save.erase(save.find(ans[j][i]));
        }

        for(int i = 0; i < m; i++) {
            if(ans[j][i] != -1) continue;
            ans[j][i] = *save.begin();
            save.erase(save.begin());
        }
    }

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
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

