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
    
    int n,m;
    string s;
    cin>>n>>m>>s;
    vector<int> a(m);
    vector<vector<int>> pref(26, vector<int>(n+1));
    for(auto &x : a) cin>>x;

    for(int i = 0; i < 26; i++) {
        for(int j = 1; j <= n; j++) {
            pref[i][j] = pref[i][j-1] + (s[j-1] - 'a' == i);
        }
    }

    vector<ll> ans(26);
    a.push_back(n);
    for(auto &x : a) {
        for(int j = 0; j < 26; j++) {
            ans[j] += pref[j][x];            
        }
    }

    for(auto &x : ans) {
        cout << x << " ";
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

