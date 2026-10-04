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
    vector<int> a(n);
    vector<bool> vis(n,false);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    sort(all(a));
    // maximal lex then b1 = an
    int i = n - 1;
    int cur = a[i];
    while(true) {
        vis[i] = true;
        cout << a[i] << " ";
        int mx = 1;
        int idx = -1;
        for(int j = n - 1; j >= 0; j--) {
            if(vis[j]) continue;
            int now = gcd(a[j],cur);
            if(now > mx) {
                mx = now;
                idx = j;
            }
        }
        if(idx == -1) break;
        i = idx;
        cur = mx;
    }
    for(int i = n - 1; i >= 0; i--) {
        if(!vis[i]) {
            cout << a[i] << " ";
        }
    }
    cout << nl;
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

