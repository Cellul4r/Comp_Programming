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
    vector<ll> odd;
    ll even = 0;
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        if(x & 1) odd.push_back(x);
        else even += x;
    }
    ll ans = 0;
    sort(all(odd));
    reverse(all(odd));
    if(!odd.empty()) {
        ans += even;
    }
    int k = (odd.size() + 1) / 2;
    for(int i = 0; i < k; i++) {
        ans += odd[i];
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

