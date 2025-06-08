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
    vector<pair<int,int>> floors;
    for(int i = 1; i <= m; i++) {
        int k;
        cin>>k;
        floors.push_back(make_pair(k / 100, k % 100));
    }
    sort(all(floors));
    
    vector<array<int,2>> ans(n);
    for(int l = 0, r = m - 1, k = 0; k < n; l++, r--, k+=2) {
        ans[k][0] = floors[l].first * 100 + floors[l].second;
        ans[k][1] = floors[r].first * 100 + floors[r].second;
        if(k < n - 1) {
            ans[k+1][0] = ans[k][1]; 
            ans[k+1][1] = ans[k][0];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= 6; j++) {
            if(j & 1) {
                cout << ans[i][0];
            } else {
                cout << ans[i][1];
            }
            cout << " ";
        }
        cout << nl;
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

