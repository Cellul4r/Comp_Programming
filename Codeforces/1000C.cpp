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
    
    map<ll,ll> cnt;
    int n;
    cin>>n;
    for(int i = 0; i < n; i++) {
        ll l,r;
        cin>>l>>r;
        cnt[l]++;
        cnt[r+1]--;
    }

    vector<ll> ans(n+1);
    ll prev_ = 0;
    ll now = 0;
    for(auto &[x,y] : cnt) {
        ans[now] += x - prev_;     
        now += y;
        prev_ = x;
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

