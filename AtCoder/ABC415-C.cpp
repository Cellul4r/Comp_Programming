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
const int N = 20;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n;
string s;
int memo[(1<<N)];
bool recur(int mask) {
    
    if(mask == (1 << n) - 1) {
        return true;
    }
    
    if(memo[mask] != -1) {
        return memo[mask];
    }
    for(int i = 0; i < n; i++) {
        if(mask & (1 << i)) continue;
        int nmask = mask | (1 << i);
        if(s[nmask-1] == '1') continue;
        if(recur(nmask)) {
            memo[mask] = 1;
            return true;
        }
    }
    memo[mask] = 0;
    return false;
}
void solve(){
    
    cin>>n>>s;
    for(int i = 0; i < (1<<n); i++) {
        memo[i] = -1;
    }
    cout << (recur(0) ? "Yes" : "No") << nl;
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

