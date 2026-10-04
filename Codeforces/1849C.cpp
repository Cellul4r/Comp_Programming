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
    
    // if that substring is already sorted -> ti = s -> no new substring
    int n,m; cin>>n>>m;
    string s; cin>>s;
    s = "$" + s;

    deque<array<int,2>> query(m);
    for(int i = 1; i <= m; i++) {
        cin>>query[i-1][0]>>query[i-1][1];
    }
    vector<int> ones(n+1, INF), zeros(n+1, -1);
    if(s[n] == '1') ones[n] = n;
    for(int i = n - 1; i >= 1; i--) {
        if(s[i] == '1') ones[i] = i;
        else ones[i] = ones[i+1];
    }
    if(s[1] == '0') zeros[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(s[i] == '0') zeros[i] = i;
        else zeros[i] = zeros[i-1];
    }
    set<array<int,2>> ans;
    for(auto &x : query) {
        int l = ones[x[0]], r = zeros[x[1]];
        if(l <= r) {
            ans.insert({l,r});
        } else {
            ans.insert({-INF,-INF});
        }
    }
    cout << ans.size() << nl;
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

