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
    vector<int> a(n+1);
    set<int> now;
    for(int i = 1; i <= n; i++) now.insert(i);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        if(a[i] > 0) now.erase(a[i]);
    }

    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) {
            a[i] = *now.rbegin();
            now.erase(*now.rbegin());
        }
    }

    ll ans = 0;
    int l = n, r = 1;
    for(int i = 1; i <= n; i++) {
        if(i != a[i]) {
            l = i;
            break;
        }
    }

    for(int i = n; i >= l; i--) {
        if(i != a[i]) {
            r = i;
            break;
        }
    }

    if(l < r) {
        ans = r - l + 1;
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

