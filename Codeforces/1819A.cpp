/* *   author : cellul4r */
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
    vector<int> a(n);
    vector<bool> vis(n+1);
    int mex = 0;
    for(auto &x : a) {
        cin>>x;
        if(x < n) vis[x] = true;
        while(vis[mex]) {
            mex++;
        }
    }

    if(mex == 0) {
        cout << "YES" << nl;
        return;
    }
    
    if(mex == n) {
        cout << "NO" << nl;
        return;
    }

    int l = -1, r = -1; 
    for(int i = 0; i < n; i++) {
        if(a[i] != mex + 1) continue;
        if(l == -1) l = i;
        r = i;
    }

    if(l == -1) {
        cout << "YES" << nl;
        return;
    }
    
    int mex2 = 0;
    for(int i = 0; i <= n; i++) vis[i] = false;
    for(int i = l; i <= r; i++) {
        a[i] = mex;
    }
    for(int i = 0; i < n; i++) {
        if(a[i] >= n) continue;
        vis[a[i]] = true;
        while(vis[mex2]) mex2++;
    }
    cerr << l << " " << r << nl;
    cerr << mex2 << nl;
    if(mex2 == mex + 1) {
        cout << "YES" << nl;
        return;
    }
    cout << "NO" << nl;
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

