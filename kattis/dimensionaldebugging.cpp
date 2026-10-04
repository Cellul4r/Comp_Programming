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
    
    int n,k;
    cin>>n>>k;
    vector<vector<int>> L(n, vector<int>(k)), H(n, vector<int>(k));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cin>>L[i][j];
        }
        for(int j = 0; j < k; j++) {
            cin>>H[i][j];
        }
    }

    vector<bool> vis(n);
    for(int i = 0; i < n; i++) {
        bool ok = true;
        for(int l = 0; l < k; l++) {
            //if(H[j][l] > H[i][l]) ok = false;
            if(L[i][l] > 0 || H[i][l] < 0) ok = false;
        }
        if(ok) vis[i] = true;
    }
    bool changed = true;
    while(changed) {
        changed = false;
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            bool found = false;
            for(int j = 0; j < n; j++) {
                if(!vis[j]) continue;
                bool ok = true;
                for(int l = 0; l < k; l++) {
                    //if(H[j][l] > H[i][l]) ok = false;
                    if(L[i][l] > H[j][l]) ok = false;
                }
                if(ok) found = true;
            }
            if(found) {
                vis[i] = true;
                changed = true;
                break;
            }
        }
    }
    int cnt = 0;
    for(auto x : vis) if(x) cnt++;
    cout << cnt;
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

