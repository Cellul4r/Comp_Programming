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
    
    string s;
    cin>>s;
    ll ans = 0;
    vector<int> cnt(2019);
    cnt[0] = 1;
    int now = 0;
    int n = s.length();
    int pow = 1;
    for(int i = n - 1; i >= 0; i--) {
        now = now + pow * (s[i] - '0');
        now %= 2019;
        pow *= 10;
        pow %= 2019;
        cnt[now]++;
    }
    for(int i = 0; i < 2019; i++) {
        if(cnt[i] == 0) continue;
        ans += 1ll * cnt[i] * (cnt[i] - 1) / 2ll;
    }
    cout << ans;
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

    //cin>>t;
    while(t--)solve();

    return 0;
}

