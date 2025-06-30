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
    ll x;
    cin>>n>>x;
    multiset<ll> a;
    for(int i = 0; i < n; i++) {
        ll k;
        cin>>k;
        a.insert(k);
    }
    int ans = 0;
    while(!a.empty()) {
        ll u = *a.begin();
        a.erase(a.begin());
        if(a.count(u * x)) {
            a.erase(a.find(u*x));
        } else {
            ans++;
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

