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
    cin>>n;
    vector<int> a(n),b(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    int ans = 0;
    vector<vector<int>> save1[2], save2[2];
    save1[0].resize(n+1);
    save1[1].resize(n+1);
    save2[0].resize(n+1);
    save2[1].resize(n+1);
    // 0 odd 1 even
    for(int i = n - 1; i >= 0; i--) {
        // check a[i] has valid for a[j] i and j has diff parity 
        // check a[i] has valid for b[j] i and j has same parity
        // check b[i] has valid for a[j] i and j has same parity
        // check b[i] has valid for b[j] i and j has diff parity
        // with erase
        // check a[i] has valid for a[j] i adn j has same parityj
        // check a[i] has valid for b[j] i and j has diff parity
        // check b[i] has valid for a[j] i and j has diff parity
        if(a[i] == b[i]) {
            ans = i + 1;
            break;
        }
        int k = (i & 1 ? 0 : 1);
        bool valid = false;
        if(!save1[k^1][a[i]].empty()) {
            valid = true;
        } else if(!save2[k][a[i]].empty()) {
            valid = true;
        } else if(!save1[k][b[i]].empty()) {
            valid = true;
        } else if(!save2[k^1][b[i]].empty()) {
            valid = true;
        } else if(!save1[k][a[i]].empty()) {
            valid = true;
        } else if(!save2[k^1][a[i]].empty() && ((int)save2[k^1][a[i]].size() == 1 && save2[k^1][a[i]][0] != i + 1)) {
            valid = true;
        } else if(!save1[k^1][b[i]].empty() && ((int)save1[k^1][b[i]].size() == 1 && save1[k^1][b[i]][0] != i + 1)) {
            valid = true;
        } else if(!save2[k][b[i]].empty()) {
            valid = true;
        }
        save1[k][a[i]].push_back(i);
        save2[k][b[i]].push_back(i);
        if(valid) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << nl;
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

