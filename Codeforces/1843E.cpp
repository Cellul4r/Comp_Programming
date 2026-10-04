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
    
    int n,m; cin>>n>>m;
    vector<array<int,2>> a(m+1);
    for(int i = 1; i <= m; i++) {
        cin>>a[i][0]>>a[i][1];
    }
    int q; cin>>q;
    vector<int> b(q+1);
    for(int i = 1; i <= q; i++) {
        cin>>b[i];
    }

    auto f = [&](int k) -> bool {
        vector<int> cur(n+1,0);
        assert(k <= q);
        for(int i = 1; i <= k; i++) {
            cur[b[i]]++;
        }

        for(int i = 1; i <= n; i++) cur[i] += cur[i-1];
        for(int i = 1; i <= m; i++) {
            int l = a[i][0], r = a[i][1]; 
            if(2 * (cur[r] - cur[l-1]) > r - l + 1) {
                return true;
            }
        }
        return false;
    };
    int l = 1, r = q;
    int target = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(f(mid)) {
            target = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << target << nl;
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

