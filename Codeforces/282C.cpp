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
    
    string a,b; cin>>a>>b;
    a = a;
    b = b;
    int n = a.size(), m = b.size();
    if(n != m) {
        cout << "NO\n";
        return;
    }
    
    vector<bool> vis(n, false);
    for(int i = 0; i < n; i++) {
        if(i - 1 >= 0 && vis[i-1]) {
            vis[i] = true;
            continue;
        }
        if(i - 1 >= 0 && (a[i-1] != '0' || a[i] != '0')) {
            if(i + 1 < n) vis[i+1] = true;
            vis[i-1] = vis[i] = true;
        }
        if(i + 1 < n && (a[i+1] != '0' || a[i] != '0')) {
            if(i - 1 >= 0) vis[i-1] = true;
            vis[i] = vis[i+1] = true;
        }
    }
    for(int i = n - 1; i >= 0; i--) {
        if(i + 1 < n && vis[i+1]) {
            vis[i] = true;
            continue;
        }
        if(i - 1 >= 0 && (a[i-1] != '0' || a[i] != '0')) {
            if(i + 1 < n) vis[i+1] = true;
            vis[i-1] = vis[i] = true;
        }
        if(i + 1 < n && (a[i+1] != '0' || a[i] != '0')) {
            if(i - 1 >= 0) vis[i-1] = true;
            vis[i] = vis[i+1] = true;
        }
    }
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i] && !vis[i]) {
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
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

