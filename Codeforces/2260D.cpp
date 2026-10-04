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
    string s; cin>>s;
    // no contiguous char '0' 
    if(s[0] == '0') {
        cout << -1 << nl;
        return;
    }
    for(int i = 0; i < n - 1; i++) {
        if(s[i] == '0' && s[i+1] == '0') {
            cout << -1 << nl;
            return;
        }
    }
    // firstly split into the group of negative , 0, and positive
    ll mx = 0;
    for(int i = 0; i < n; i++) {
        int j = i;
        vector<bool> parity;
        char cur = '0';
        int cnt = 0;
        while(j < n && s[j] != '0') {
            if(cur == '0') {
                cur = s[j];
                cnt = 1;
            } else if(cur == s[j]){
                cnt++;
            } else {
                parity.push_back(cnt % 2);
                cnt = 1;
                cur = s[j];
            }
            j++;
        }
        if(cnt > 0) {
            parity.push_back(cnt % 2);
        }
        ll now = 1;
        if(parity.size() >= 1) {
            int m = parity.size();
            ll cur = (parity[0] ? 1 : 2);
            now = max(cur, now);
            for(int i = 1; i < m; i++) {
                cur = (cur == 1 ? 2 : 3);
                now = max(now, cur);
            }
        }
        mx = max(mx, now);
        i = j;
    }
    cout << mx << nl;
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

