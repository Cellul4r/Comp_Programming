/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n,m,k; cin>>n>>m>>k;
    vector<int> a(k);
    for(int i = 0; i < k; i++) {
        cin>>a[i];
    }
    vector<bool> vis(k+1, false);
    int sz = 0;
    int idx = 0;
    for(int i = k; i >= 1; i--) {
        if(vis[i]) {
            sz--;
            continue;
        }
        while(a[idx] != i) {
            assert(idx < k);
            vis[a[idx]] = true;
            sz++;
            idx++;
        }
        if(sz >= n*m-3) {
            cout << "TIDAK\n";
            return;
        }
        vis[i] = true;
        idx++;
    }
    cout << "YA\n";
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

