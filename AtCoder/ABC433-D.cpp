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
    ll m; cin>>n>>m;
    vector<ll> a(n), b(n);
    vector<int> pow10(11);
    pow10[0] = 1 % m;
    for(int i = 1; i <= 10; i++) {
        pow10[i] = (10 * pow10[i-1]) % m;
    }

    map<int,ll> cnt[11];
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        for(int j = 0; j <= 10; j++) {
            ll cur = (a[i] * pow10[j]) % m;
            cnt[j][cur]++;
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; i++) {
        int need = (m - a[i] % m) % m;
        int d = 0;
        while(a[i] > 0) {
            d++;
            a[i] /= 10;
        }
        ans += cnt[d][need];
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

