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
    
    int n; cin>>n;
    vector<array<int,2>> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i][0]>>a[i][1];
    }
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
        if(a[i][0] != a[j][0]) {
            return a[i][0] < a[j][0];
        }
        return a[i][1] < a[j][1];
    });
    vector<int> ans(n,1);
    int ar = a[ord[0]][1];
    for(int i = 1; i < n; i++) {
        auto &x = a[ord[i]];
        if(x[0] > ar) {
            for(int j = i; j < n; j++) {
                ans[ord[j]] = 2;
            }
            for(int k = 0; k < n; k++) {
                cout << ans[k] << " ";
            }
            cout << nl;
            return;
        }
        ar = max(ar, x[1]);
    }
    cout << -1 << nl;
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

