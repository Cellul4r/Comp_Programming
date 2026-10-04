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
    
    int n; cin>>n;
    vector<ll> a;
    int cnt = 0, cur = -1;
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        if(x == cur) {
            cnt++;
            continue;
        }
        if(cnt > 0) {
            a.push_back(cnt);
        }
        cnt = 1;
        cur = x;
    }
    assert(cnt >= 1);
    a.push_back(cnt);
    int m = a.size();
    vector<ll> pref(m+1, 0ll);
    for(int i = 1; i <= m; i++) {
        pref[i] = pref[i-1] + a[i-1];
    }

    vector<ll> ans{0,0,0};
    ll mx = n / 2ll, sum = 0;
    for(int i = 1; i <= m; i++) {
        vector<ll> now{0,0,0}; 
        // i is number of gold we will give.
        // j = i + 1 number of silver we will give
        // k = i + 1 min number of bronze we will give
        now[0] = pref[i];
        // minimum index in the prefix such that pref[idx] > pref[i] + pref[i]
        int idx = lower_bound(all(pref), 2ll * pref[i]) - pref.begin();
        if(idx == m+1) continue;
        now[1] = pref[idx] - pref[i];
        int mn = min(m,idx);
        // maximum we can give bronze binary search
        // maximum index in the prefix such that pref[idx] >= max(0,mx - now[0] - now[1]) + pref[2*i+1]
        ll k = max(0ll, mx - now[0] - now[1]);
        idx = upper_bound(all(pref), pref[mn] + k) - pref.begin();
        if(idx > mn) {
            idx--;
        }
        now[2] = pref[idx] - pref[mn];
        if(now[0] >= now[1] || now[0] >= now[2]) continue;
        if(now[0] + now[1] + now[2] > mx) continue;
        if(sum < now[0]+now[1]+now[2]) {
            sum = now[0]+now[1]+now[2];
            ans = now;
        }
    }
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

