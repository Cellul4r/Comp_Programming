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

    vector<bool> ok(n,true);
    vector<pi> a(n);
    for(auto &x : a) {
        cin>>x.first>>x.second;
    }

    vector<int> ans;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;

            if(a[j].first <= a[i].first && a[i].second <= a[j].second) ok[i] = false;
        }
        if(ok[i]) ans.push_back(i);
    }
    cout << ans.size() << nl;
    for(auto &x : ans) cout << x + 1 << " ";
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

