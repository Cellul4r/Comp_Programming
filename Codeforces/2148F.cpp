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
    
    int n; cin>>n;
    multiset<vector<int>> a;
    int cur = 0;
    int mx = 0;
    for(int i = 0; i < n; i++) {
        int k; cin>>k;
        mx = max(mx, k);
        vector<int> now(k);
        for(auto &x : now) {
            cin>>x;
        }
        a.insert(now);
    }

    vector<int> ans;
    while(cur < mx) {
        assert(!a.empty());
        auto &x = *a.begin();
        if((int)x.size() <= cur) {
            a.erase(a.begin());
            continue;
        }
        for(int i = cur; i < (int)x.size(); i++) {
            ans.push_back(x[i]);
        }
        cur = x.size();
        a.erase(a.begin());
    }

    for(auto &x : ans) cout << x << " ";
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

