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
    
    int n,l,r;
    string s;
    cin>>n>>l>>r>>s;
    vector<vector<int>> a(26);
    for(int i = 0; i < n; i++) {
        a[s[i]-'a'].push_back(i);
    }

    ll ans = 0;
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < (int)a[i].size(); j++) {
            int x = a[i][j];
            auto ll = lower_bound(all(a[i]), l + x) - a[i].begin();
            auto rr = upper_bound(all(a[i]), r + x) - a[i].begin();
            if(ll < rr) ans += 1ll * rr - ll;
        }
    }
    cout << ans;
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

