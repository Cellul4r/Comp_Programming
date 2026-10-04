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
    // even even even even even -> 0
    // odd odd even -> even even even -> 1
    // odd even odd -> 
    // even odd even
    // odd even even even even even even odd -> 4
    // 0 00 01 1 -> 3
    // 1 00 1 -> 0000 -> 2
    // 1 00 11 00 1 -> 4
    // 111 00 11 000 -> 3
    vector<int> odd;
    int cur = (s[0] == '0' ? 0 : 1), cnt = 1;
    int now = 0;
    for(int i = 1; i < n; i++) {
        if(cur == s[i] - '0') {
            cnt++;
            continue;
        }
        if(cnt % 2 == 1) {
            odd.push_back(now);
        }
        cur = s[i] - '0';
        cnt = 1;
        now++;
    }
    if(cnt % 2 == 1) {
        odd.push_back(now);
    }
    assert(odd.size() % 2 == 0);
    ll ans = 0;
    for(int i = 0; i < (int)odd.size(); i += 2) {
        ans += (odd[i+1] - odd[i]);
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

