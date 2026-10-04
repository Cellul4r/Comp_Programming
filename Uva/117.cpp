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
    
    string s;
    while(cin>>s) {
        vector<int> deg(26);
        vector<vector<int>> w(26,vector<int>(26, INF));
        for(int i = 0; i < 26; i++) w[i][i] = 0;
        int ans = 0;
        while(true) {
            if(s == "deadend") break;
            int n = s.length();
            deg[s[0]-'a']++;
            deg[s[n-1]-'a']++;
            w[s[0]-'a'][s[n-1]-'a'] = n;
            w[s[n-1]-'a'][s[0]-'a'] = n;
            ans += n;
            cin>>s;
        }

        vector<int> odd;
        for(int i = 0; i < 26; i++) {
            if(deg[i] & 1) {
                odd.push_back(i);
            }
        }

        if(odd.size()) {
            for(int k = 0; k < 26; k++) {
                for(int i = 0; i < 26; i++) {
                    for(int j = 0; j < 26; j++) {
                        w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
                    }
                }
            }
            ans += w[odd[0]][odd[1]];
        }
        cout << ans << nl;
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

