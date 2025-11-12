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
    if(n % 2 == 0) {
        cout << -1 << nl;
        return;
    }

    vector<int> ans(n);
    for(int i = n / 2 + 1, cur = 2; i < n; i++, cur += 2) {
        ans[i] = cur; 
    }
    for(int i = n / 2, cur = 1; i >= 0; i--, cur += 2) {
        ans[i] = cur;
    }
    for(auto &x : ans) cout << x << " ";
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

