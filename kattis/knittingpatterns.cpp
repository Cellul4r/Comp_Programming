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
    
    ll a,b,c;
    cin>>a>>b>>c;
    vector<int> idx(26,-1);
    string s,t; cin>>s>>t;
    for(int i = 0; i < (int)s.size(); i++) {
        idx[s[i]-'a'] = i+1;
    }
    vector<ll> ans(s.size()+1);
    vector<int> pos[26];
    for(int i = 0; i < (int)t.size(); i++) {
        pos[t[i]-'a'].push_back(i);
    }
    for(int i = 0; i < 26; i++) {
        if(pos[i].empty()) continue;
        int k = idx[i];
        ans[k] += b * pos[i].size();
        ans[k] += c * 2;
        for(int j = 1; j < (int)pos[i].size(); j++) {
            ans[k] += min(c * 2,a * (pos[i][j] - pos[i][j-1] - 1));
        }
    }
    for(int i = 1; i <= (int)s.size(); i++) cout << ans[i] << nl;
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

