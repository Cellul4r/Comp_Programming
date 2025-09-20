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
    
    ll n,k; cin>>n>>k;
    vector<vector<int>> a(n+1);
    vector<int> b(n+1);
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        a[x].push_back(i);
        b[i] = x;
    }
    for(int i = 1; i <= n; i++) {
        if(a[i].size() % k != 0) {
            cout << 0 << nl;
            return;
        }
    }

    ll ans = 0;
    vector<int> cnt(n+1);
    int l,r;
    l = r = 1;
    r = 0;
    while(l <= n) {
        while(r+1 <= n && cnt[b[r+1]] + 1 <= (ll)a[b[r+1]].size() / k) {
            r++;
            cnt[b[r]]++;
        }
        ans += r - l;
        cnt[b[l]]--;
        l++;
    }
    /*ll ans = n * (n + 1) / 2ll;
    for(int i = 1; i <= n; i++) {
        ll cur = 1ll * a[i].size() / k;
        for(int j = 0; j < (int)a[i].size() - cur; j++) {
            int r = j + cur;
            cerr << j << " " << r << " " << n - a[i][r] + 1 << nl;
            ans -= 1ll * (n - a[i][r] + 1);
        }
    }*/
    cout << ans + n << nl;
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

