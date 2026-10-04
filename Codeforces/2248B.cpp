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
    vector<int> a(n), b(m);
    for(auto &x : a) {
        cin>>x;
    }
    for(auto &x : b) {
        cin>>x;
    }
    sort(all(a));
    sort(all(b));

    if(n < m) {
        cout << "NO\n";
        return;
    }
    if(n == m) {
        cout << (a == b ? "YES\n" : "NO\n");
        return;
    }

    int j = m;
    bool ok = true;
    for(int k = 0; k < m; k++) {
        // assume 
        while(j < n && a[j] < b[k]) {
            j++;
        }
        if(j >= n || a[k] > b[k]) {
            ok = false;
            break;
        }
        //cout << k << " " << j << nl;
        j++;
    }
    cout << (ok ? "YES\n" : "NO\n");
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

