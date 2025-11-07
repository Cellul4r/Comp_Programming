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
    multiset<int> a;
    vector<int> b(m), c(m);
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        a.insert(x);
    }
    for(auto &x : b) {
        cin>>x;
    }
    for(auto &x : c) {
        cin>>x;
    }

    vector<int> ord(m);
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) {
                return b[i] < b[j];
            });
    int ans = 0;
    for(auto &i : ord) {
        if(c[i] == 0) continue;
        auto it = a.lower_bound(b[i]);
        if(it == a.end()) continue;
        int k = max(*it, c[i]);
        a.erase(it);
        a.insert(k);
        ans++;
    }
    for(auto &i : ord) {
        if(c[i] != 0) continue;
        auto it = a.lower_bound(b[i]);
        if(it == a.end()) continue;
        ans++;
        a.erase(it);
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

