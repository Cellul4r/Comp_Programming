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
    
    ll n;
    string s; cin>>n>>s;
    // day i must pay i coin but available from day i to day n
    // 101101
    // 1+2+3+4+5+6 = 6*7/2 = 21 - ?
    // 1 + 0 * 3
    // 2 + 0 * 4
    // 5 + 0 * 6
    // 1110001
    // ? + 0 * 7 (6,5,4)
    // ? + 0 * 3 (1)
    // ? + 0 * 2

    ll ans = n * (n + 1) / 2ll;
    vector<ll> a;
    for(int i = 2; i <= n; i++) {
        if(s[i-1] == '1') a.push_back(i);
    }
    reverse(all(a));
    // last f(x) that is true
    auto f = [&](int k) {
        // idx <= k must be free
        if(k < 0 || k >= (int)a.size()) return false;
        vector<bool> vis(n+1);
        for(int i = 0; i <= k; i++) {
            vis[a[i]] = true; 
        }
        int now = n;
        bool ok = true;
        for(int i = 0; i <= k; i++) {
            while(now >= 1 && (now >= a[i] || vis[now])) {
                now--;
            }
            if(now == 0) {
                ok = false;
                break;
            }
            vis[now] = true;
        }
        return ok;
    };

    int l = -1, r = a.size() - 1;
    while(l < r) {
        int mid = l + (r - l + 1) / 2;
        if(f(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    //cerr << l << nl;
    for(int i = 0; i <= l; i++) {
        ans -= a[i];
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

