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
    vector<string> ans;
    string now;
    char prv = '$';
    for(auto &x : s) {
        if(prv != '$' && prv != x) {
            ans.push_back(now);
            now = "";
        }
        now += x;
        prv = x;
    }
    if(!now.empty()) {
        ans.push_back(now);
    }
    cout << ans[0];
    for(int i = 1; i < (int)ans.size(); i++) {
        cout << "|" << ans[i];
    }
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

