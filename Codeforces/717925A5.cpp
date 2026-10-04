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

    string s; cin>>s;
    int n = s.size();
    vector<ll> pref(n);
    pref[0] = (s[0] - 'a' + 1);
    for(int i = 1; i < n; i++) {
        pref[i] += pref[i-1] + (s[i] - 'a' + 1);
    }

    ll cur = pref[n-1];
    auto f = [&](int k) -> bool {
        ll now = 0;
        //cout << k << nl;
        for(int i = 1; i <= cur / k; i++) {
            auto idx = lower_bound(all(pref), now + k) - pref.begin();
            if(idx == n || pref[idx] != now + k) return false;
            now += 1ll * k;
        }
        return true;
    };

    int ans = INT_MAX;
    for(int i = 1; i * i <= cur; i++) {
        if(cur % i != 0) continue;
        if(f(i)) {
            ans = min(ans, i);
        }
        if(cur / i != i && f(cur / i)) {
            ans = min(1ll *ans, cur / i);
        }
    }
    string t;
    int now = 0;
    for(auto &x : s) {
        t += x;
        now += x - 'a' + 1;
        if(now == ans) {
            t += "|";
            now = 0;
        }
    }
    assert(t.back() == '|');
    t.pop_back();
    cout << t;
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

