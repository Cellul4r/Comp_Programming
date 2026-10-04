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
const int N =35;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int a[N][N];
bool vis[N];
string s;
vector<char> var;
int n = 0;
set<string> ans;
int idx = 0;
void recur(int i, string cur) {
    if(i == n) {
        ans.insert(cur);
        return;
    }

    for(int j = 0; j < n; j++) {
        if(vis[var[j]-'a']) continue;
        bool ok = true;
        for(int k = 0; k < n; k++) {
            if(a[var[j]-'a'][var[k]-'a'] == 1 && vis[var[k]-'a']) {
                ok = false;
            }
            if(a[var[j]-'a'][var[k]-'a'] == 2 && !vis[var[k]-'a']) {
                ok = false;
            }
        }
        if(ok) {
            vis[var[j]-'a'] = true;
            recur(i+1, cur + var[j]);
            vis[var[j]-'a'] = false;
        }
    }
}
void solve(){
    
    while(getline(cin,s)) {
        stringstream ss(s);
        string k;
        n = 0;
        memset(a, 0, sizeof a);
        memset(vis, false, sizeof vis);
        ans.clear();
        var.clear();
        while(ss>>k) {
            var.push_back(k[0]);
            n++;
        }
        getline(cin,s);
        stringstream cur(s);
        char x,y;
        while(cur>>x) {
            cur>>y;
            a[x-'a'][y-'a'] = 1;
            a[y-'a'][x-'a'] = 2;
        }
        recur(0,"");
        if(idx > 0) {
            cout << nl;
        }
        for(auto &x : ans) {
            cout << x << nl;
        }
        idx++;
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

