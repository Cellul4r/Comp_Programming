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
    
    int n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;
    vector<string> ans;
    for(int op = 0; op < k && s != t; op++) {
        /*
         * 
            1
            5 5
            acabb
            acaca
        */
        vector<int> seen(26,-1);
        vector<bool> shift(n, false);
        for(int i = 0; i < n; i++) {
            seen[s[i]-'a'] = i;
            if(s[i] == t[i]) continue;
            int j = seen[t[i]-'a'];
            if(j == -1) {
                cout << -1 << nl << nl;
                return;
            }
            shift[j] = true; 
        }

        for(int i = n-1; i >= 0; i--) {
            if(shift[i]) {
                s[i+1] = s[i];
            }
        }
        ans.push_back(s);
    }

    if(s != t) {
        cout << -1 << nl << nl;
        return;
    }
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x << nl;
    }
    cout << nl;
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

