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
    cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    ll ans = LINF;
    for(int i = 1; i <= n; i++) {
        int j = i;
        while(j <= n && a[j] == a[i]) {
            j++;
        }
        ans = min(ans, 1ll * (i-1) * a[i] + 1ll * (n - j + 1) * a[i]);
        i = j - 1;
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

