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
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int k;
int dp[N][2];
int recur(int i, int prev, vector<int>& c, int& n) {
    if(i == n) {
        return 1;
    }

    //cout << i << " " << prev << nl;
    if(dp[i][prev] != -1) return dp[i][prev];
    int found = 0;
    if(prev) {
        assert(i > 0);
        if(c[i] - c[i-1] <= 2) found |= recur(i+1, 0, c, n);
        if(c[i] - c[i-1] == 1) {
            found |= recur(i+1, 1, c, n);
        }
    } else {
        if(c[i] == 1 || (i - 1 >= 0 && c[i] - c[i-1] == 1)) {
            found |= recur(i+1, 0, c, n);
        }
        if(c[i] == k || (i + 1 < n && c[i+1] - c[i] <= 2)) {
            found |= recur(i+1, 1, c, n);
        }
    }

    return dp[i][prev] = found;
}
void solve(){
    
    int n; cin>>n;
    k = n;
    string s; cin>>s;

    if(n <= 2) {
        cout << "YES\n";
        return;
    }
    vector<int> a;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') a.push_back(i+1);
    }

    n = a.size();
    if(a.empty()) {
        cout << "YES\n";
        return;
    }

    if(n == 1) {
        cout << (a[0] == 1 || a[0] == k ? "YES" : "NO") << nl;
        return;
    }
    // 2 or more rabbits
    // first check if there are rabbits that no their match with diff <= 2
    bool ok = true;
    vector<int> b(n,-1);
    for(int i = 0; i < n; i++) {
        int& x = a[i];
        bool found = false;
        if(i - 1 >= 0 && x - a[i-1] <= 2) {
            found = true;
        } else if(i + 1 < n && a[i+1] - x <= 2) {
            found = true;
        } else if(a[i] == 1 || a[i] == k) {
            b[i] = (a[i] == 1 ? 0 : 1);
            found = true;
        }
        if(!found) ok = false;
    }
    if(!ok) {
        cout << "NO\n";
        return;
    }

    vector<int> c;
    for(int i = 0; i < n; i++) {
        if(b[i] == -1) {
            c.push_back(a[i]);
        }
    }

    n = c.size();
    memset(dp, -1, sizeof dp);
    cout << (recur(0,0,c,n) ? "YES" : "NO") << nl;
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

