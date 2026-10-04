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
    
    int n,m; cin>>n>>m; 
    vector<int> cur(26, 0);
    vector<string> a;
    vector<bool> vis(m, false);
    for(int i = 0; i < n + m; i++) {
        string s; cin>>s; 
        if(s[0] >= 'a' && s[0] <= 'z') {
            cur[s[0]-'a']++;
        } else {
            a.push_back(s);
        }
    }
    int now = 0;
    while(now < m) {
        bool found = false;
        for(int i = 0; i < m; i++) {
            if(vis[i]) continue;
            bool ok = true;
            for(auto &x : a[i]) {
                if(cur[x-'A'] == 0) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                found = true;
                vis[i] = true;
                cur[a[i][0]-'A']++;
                now++;
                break;
            }
        }
        if(!found) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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

