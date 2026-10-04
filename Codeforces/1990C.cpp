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
    vector<ll> a(n);
    ll ans = 0;
    for(auto &x : a) {
        cin>>x;
        ans += x;
    }
    vector<int> cnt(n+1, 0);
    ll cur = 0;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cnt[a[i]]++;
        if(cnt[a[i]] >= 2) {
            cur = max(cur, a[i]);
        }
        a[i] = cur;
        sum += a[i];
    }
    ans += sum;
    sum = 0;
    cnt.assign(n+1, 0);
    cur = 0;
    for(int i = 0; i < n; i++) {
        cnt[a[i]]++;
        if(cnt[a[i]] >= 2) {
            cur = max(cur, a[i]);
        }
        a[i] = cur;
        sum += a[i];
    }
    ans += sum;
    for(int i = n - 1; i >= 0; i--) {
        if(a[i] == 0) break;
        sum -= a[i];
        ans += sum;
    }
    // 2 3 4 5 5 6 6 7 8 8
    // 0 0 0 0 5 5 6 6 6 8
    // 0 0 0 2 2 2 4 4
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

