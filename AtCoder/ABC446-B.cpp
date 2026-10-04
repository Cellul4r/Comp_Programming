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
    
    int n,m; cin>>n>>m;
    set<int> now;
    for(int i = 1; i <= m; i++) now.insert(i);
    for(int i = 0; i < n; i++) {
        int l; cin>>l;
        vector<int> cur(l);
        for(int j = 0; j < l; j++) {
            cin>>cur[j]; 
        }
        int ans = 0;
        for(auto &x : cur) {
            if(now.count(x)) {
                now.erase(x);
                ans = x;
                break;
            }
        }
        cout << ans << nl;
    }
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

