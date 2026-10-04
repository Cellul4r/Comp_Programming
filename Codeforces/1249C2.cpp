/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    ll n;
    cin>>n;
    // 3^0 = 1
    // 3^1 = 3
    // suppose 3^k >= n how can we reduce the number?
    // 3^38
    int idx = -1;
    vector<ll> cur;
    ll tmp = n;
    while(tmp > 0) {
        cur.push_back(tmp % 3ll);
        tmp /= 3ll;
    }
    cur.push_back(0);
    int m = cur.size();
    for(int i = 0; i < m; i++) {
        if(cur[i] == 2) {
            idx = i;
        }
    }
    if(idx == -1) {
        cout << n << nl;
        return;
    }
    for(int i = 0; i < idx; i++) {
        cur[i] = 0;
    }
    cur[idx]++;
    int i = idx;
    //cout << idx << nl;
    while(i < m - 1) {
        if(cur[i] >= 2) {
            cur[i] = 0;
            cur[i+1]++;
        }
        i++;
    }
    ll ans = 0;
    ll x = 1;
    for(int i = 0; i < m; i++) {
        assert(cur[i] <= 1);
        ans += cur[i] * x;
        x *= 3ll;
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

