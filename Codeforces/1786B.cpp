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
    
    int n,w,h; cin>>n>>w>>h;
    vector<int> a(n),b(n);
    for(auto &x : a) {
        cin>>x;
    }
    for(auto &x : b) {
        cin>>x;
    }
    int l = -INF, r = INF;
    for(int i = 0; i < n; i++) {
        l = max(l, a[i] - (b[i] - h + w));
        r = min(r, a[i] - (b[i] + h - w));
        //cerr << l << " " << r << nl;
    }

    if(l > r) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
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

