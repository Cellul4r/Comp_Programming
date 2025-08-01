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
    vector<ll> a(n),b(n),c(n),d(n);
    ll zero = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        if(a[i] > c[i]) {
            zero += a[i] - c[i];
        }
        // move early 1's
    }
    for(int i = 0; i < n; i++) {
        //move zero
        if(a[i] < c[i]) {
            ans += c[i] - a[i];
            zero -= c[i] - a[i];
        }
    }
    for(int i = 0; i < n; i++) {
        if(b[i] > d[i]) {
            ans += min(a[i],c[i]);
        }
    }

    for(int i = 0; i < n; i++) {
        if(b[i] < d[i]) {
            ans += d[i] - b[i];
        }
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

