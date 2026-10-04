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
    
    string s; cin>>s;
    ll ans = 0;
    string t;
    for(auto &x : s) {
        if(x == '4') {
            ans++;
        } else {
            t += x;
        }
    }
    s = t;
    int n = s.size();
    vector<ll> pre(n+1), suff(n+1);
    pre[0] = (!s.empty() && s[0] == '2' ? 1 : 0);
    for(int i = 1; i < n; i++) {
        if(s[i] == '2') pre[i] = 1;
        pre[i] += pre[i-1];
    }
    for(int i = n - 1; i >= 0; i--) {
        if(s[i] == '1' || s[i] == '3') suff[i]++;
        suff[i] += suff[i+1];
    }
    ll cur = ans;
    ans = 0;
    ans = max(ans, suff[0]);
    for(int i = 0; i < n; i++) {
        ans = max(ans, pre[i] + suff[i+1]); 
    }
    cout << n - ans + cur << nl;
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

