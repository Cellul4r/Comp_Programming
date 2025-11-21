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
    
    int n;
    cin>>n;
    vector<vector<int>> idx(n);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        x--;
        idx[x].push_back(i);
    }

    int ans = INF;
    for(int i = 0; i < n; i++) {
        if(idx[i].empty()) continue;
        int now = 0;
        int prv = -1;
        for(auto &x : idx[i]) {
            if(x > prv + 1) {
                now++;
            }
            prv = x;
        }
        if(idx[i].back() != n - 1) now++; 
        ans = min(ans, now);
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

