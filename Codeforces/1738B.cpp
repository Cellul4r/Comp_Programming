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
    
    int n,k;
    cin>>n>>k;
    vector<ll> a(k);
    for(auto &x : a) cin>>x; 
    if(k == 1) {
        cout << "YES" << nl;
        return;
    }
    bool flag = true;
    ll cur = -LINF;
    for(int i = 0; i < k - 1; i++) {
        ll now = a[i+1] - a[i];
        if(now < cur) {
            flag = false;
        }
        cur = now;
    }
    if(a[0] > 1ll * (n - k + 1) * (a[1] - a[0])) {
        flag = false;
    }
    cout << (flag ? "YES" : "NO") << nl;
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

