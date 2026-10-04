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
    
    // (1,10)
    // (2, 3) if at some point li contain cnt >= 2 then the answer always exists that is (li, ri) <- (li, rj) 
    // (2, 9)
    // (2, 9)
    // (3, 9)
    int n; cin>>n;
    vector<array<int,2>> a;
    for(int i = 1; i <= n; i++) {
        int l,r; cin>>l>>r;
        a.push_back({l,r});
    }
    vector<int> ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
                if(a[i][0] != a[j][0]) {
                    return a[i][0] < a[j][0];
                }
                return a[i][1] < a[j][1];
            });
    int mx = 0;
    int idx = -1;
    for(int i = 0; i < n; i++) {
        int now = ord[i];
        if(a[now][1] <= mx) {
            cout << now + 1 << " " << idx + 1 << nl;
            return;
        }
        mx = a[now][1];
        idx = now;
        if(i < n - 1) {
            if(a[now][0] == a[ord[i+1]][0]) {
                cout << now + 1 << " " << ord[i+1] + 1 << nl;
                return;
            }
        }
    }
    cout << -1 << " " << -1 << nl;
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

