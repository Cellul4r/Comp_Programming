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
    vector<vector<int>> a(n);
    vector<int> cnt(m+1);
    for(int i = 0; i < n; i++) {
        int l; cin>>l;
        for(int j=0; j < l; j++) {
            int x; cin>>x;
            a[i].push_back(x);
            cnt[x]++;
        }
    }
    for(int i = 1; i <= m; i++) {
        if(cnt[i] == 0) {
            cout << "NO\n";
            return;
        }
    }

    ll ans = 1;
    for(int i = 0; i < n; i++) {
        bool ok = true;
        for(int j = 0; j < (int)a[i].size(); j++) {
            cnt[a[i][j]]--;
            if(cnt[a[i][j]] == 0) {
                ok = false;
            }
        }
        for(int j = 0; j < (int)a[i].size(); j++) {
            cnt[a[i][j]]++;
        }
        if(ok) ans++;
    }
    cout << (ans >= 3 ? "YES" : "NO") << nl;
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

