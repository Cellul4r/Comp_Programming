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

void solve(){
    
    string s;
    int q;
    cin>>s>>q;
    int n = s.length();
    vector<vector<int>> pre(26, vector<int>(n+1));
    for(int i = 0; i < n; i++) {
        pre[s[i]-'a'][i+1] = 1;
    }

    for(int i = 0; i < 26; i++) {
        for(int j = 1; j <= n; j++) {
            pre[i][j] += pre[i][j-1];
        }
    }

    for(int i = 0; i < q; i++) {
        int l,r;
        cin>>l>>r;
        int cnt = 0;
        for(int k = 0; k < 26; k++) {
            if(pre[k][r] - pre[k][l-1] > 0) cnt++;
        }
        cout << (cnt > 2 || l == r || s[l-1] != s[r-1] ? "Yes" : "No");
        cout << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    //cin>>t;
    while(t--)solve();

    return 0;
}

