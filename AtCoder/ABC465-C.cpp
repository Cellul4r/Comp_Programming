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
    vector<int> cur;
    vector<vector<int>> a;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'x') {
            cur.push_back(i);
        } else {
            cur.push_back(i);
            a.push_back(cur);
            cur.clear();
        }
    }
    reverse(all(a));
    int m = a.size();
    for(int i = 0; i < m; i += 2) {
        for(int j = a[i].size() - 1; j >= 0; j--) {
            cout << a[i][j] + 1 << " ";
        }
    }
    int start = (m % 2 == 0 ? m - 1 : m - 2);
    for(int i = start; i >= 0; i -= 2) {
        for(int j = 0; j < (int)a[i].size(); j++) {
            cout << a[i][j] + 1 << " ";
        }
    }
    if(!cur.empty()) {
        for(auto &x : cur) {
            cout << x + 1 << " ";
        }
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

