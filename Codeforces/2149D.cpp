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
ll check(int idx, vector<int>& a, int& n) {
    if(a.empty()) return LINF;
    ll ans = 0;
    //cerr << n << nl;
    int cur = a[idx] - 1;
    //cerr << idx << nl;
    for(int i = idx - 1; i >= 0; i--) {
        //cerr << i << " " << a[i] << " " << cur << nl;
        ans += 1ll * cur - a[i];
        cur--;
    }
    cur = a[idx] + 1;
    //cerr << nl;
    for(int i = idx + 1; i < (int)a.size(); i++) {
        //cerr << i << " " << a[i] << nl;
        ans += 1ll * a[i] - cur;
        cur++;
    }
    return ans;
}
void solve(){
    
    int n; cin>>n;
    string s; cin>>s;
    string t = s;
    // aaaa..bbbb..
    if(n == 1) {
        cout << 0 << nl;
        return;
    }
    s = t;
    ll ans5 = 0, ans6 = 0;
    vector<int> a,b;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') a.push_back(i);
        else b.push_back(i);
    }
    // a middle
    ans5 = check(a.size() / 2, a, n);
    if(!a.empty() && a.size() % 2 == 0) {
        ans5 = min(ans5, check(a.size() / 2 - 1, a, n));
    }
    ans6 = check(b.size() / 2, b, n);
    if(!b.empty() && b.size() % 2 == 0) {
        ans5 = min(ans5, check(b.size() / 2 - 1, b, n));
    }
    cout << min(ans5, ans6) << nl;
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

