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
const ll INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    string s; cin>>s;
    int n = s.length();

    map<int,ll> cnt, save;
    int cur = 0;
    for(int i = 1; i <= n; i++) {
        cur += (s[i-1] == '0' ? -1 : 1);
        cnt[cur] += i;
        save[cur]++;
    }

    ll ans = 0;
    cur = 0;
    for(int i = 1; i <= n; i++) {
        // find all sum such that has sum = now
        //cerr << "NOW: " << cur << " " << i << " " << save[cur] << " S: " << cnt[cur] << nl;
        ll x = 1ll * i * (save[cur] * (n + 1) - cnt[cur]) % INF;
        ans = (ans + x) % INF;

        cur += (s[i-1] == '0' ? -1 : 1);
        cnt[cur] -= i;
        save[cur]--;
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

