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
    ll k; cin>>n>>k;
    set<ll> vis;
    set<ll> now;
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        now.insert(x);
    }
    bool ok = true;
    vector<ll> ans;
    for(auto &x : now) {
        if(vis.count(x)) continue;
        ans.push_back(x);
        for(int j = x; j <= k; j += x) {
            if(now.count(j) == 0) {
                ok = false;
                break;
            }
            vis.insert(j);
        }
        if(!ok) break;
    }
    if(!ok) {
        cout << -1 << nl;
        return;
    }

    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x << " ";
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

