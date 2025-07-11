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

void solve(){
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<int,int> cnt;
    vector<int> pre(n+1);
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        pre[i+1] = (s[i] - '0') + pre[i];
    }
    for(int i = 1; i <= n; i++) {
        cnt[pre[i-1] - i + 1]++;
        ans += cnt[pre[i] - i];
    }
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

