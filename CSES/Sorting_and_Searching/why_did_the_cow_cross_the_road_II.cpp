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

void solve(){
    
    int n,k,b;
    cin>>n>>k>>b;
    vector<int> pre(n+1);
    for(int i = 0; i < b; i++) {
        int x;
        cin>>x;
        pre[x] = 1;
    }

    for(int i = 1; i <= n; i++) {
        pre[i] += pre[i-1];
    }
    int ans = INF;
    for(int i = 1; i <= n - k; i++) {
        ans = min(ans, pre[i+k] - pre[i]); 
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    ///*
    string s = "maxcross";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    //*/

    //cin>>t;
    while(t--)solve();

    return 0;
}

