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
    
    int n;
    string a,b; cin>>n>>a>>b;
    bool eq = false, neq = false;
    for(int i = 0; i < n; i++) {
        if(a[i] == b[i]) {
            eq = true;
        } else {
            neq = true;
        }
    }
    if(eq && neq) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<array<int,2>> ans;
    for(int i = 0; i < n; i++) {
        if(a[i] == '0') {
            ans.push_back({i+1,i+1});
        }
    }
    int now = ans.size();
    if(eq) {
        if(now % 2 == 0) {
            ans.push_back({1,1});
            ans.push_back({2,n});
        } else {
            ans.push_back({1,n});
        }
    } else {
        if(now % 2 == 0) {
            ans.push_back({1,n});
        } else {
            ans.push_back({1,1});
            ans.push_back({2,n});
        }
    }
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x[0] << " " << x[1] << nl;
    }
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

