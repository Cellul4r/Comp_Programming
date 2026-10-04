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
    vector<int> cnt(26, 0);
    int bad = 0;
    for(auto &x : s) {
        now += x;
        if(cnt[x-'a'] % 2 == 0) {
            bad++;
        } else {
            bad--;
        }
        cnt[x-'a']++;
        if(bad == 0) {
            ans.push_back(now);
            for(int i = 0; i < 26; i++) {
                cnt[i] = 0;
            }
            now = "";
        }
    }
    if(!now.empty()) {
        if(ans.empty()) ans.push_back(now);
        else ans.back() += now;
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

