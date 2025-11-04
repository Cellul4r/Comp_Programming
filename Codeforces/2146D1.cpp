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
    
    int l, r; cin>>l>>r;
    assert(l == 0);
    int n = r + 1;
    int lg = 0;
    while((1<<lg) <= n) lg++;
    vector<ll> ans(n);
    ll sum = 0; 
    int k = (1 << lg) - 1;
    set<int> save;
    for(int i = l; i <= r; i++) save.insert(i);
    for(int i = r; i >= l; i--) {
        while(!save.count(k ^ i)) {
            k >>= 1;
        }
        ans[i] = k ^ i;
        save.erase(k ^ i);
    }
    for(int i = 0; i < n; i++) {
        sum += (ans[i] | i);
    }
    cout << sum << nl;
    for(auto &x : ans) {
        cout << x << " ";
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

