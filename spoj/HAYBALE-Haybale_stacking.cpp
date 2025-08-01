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
    
    int n,k;
    cin>>n>>k;
    vector<ll> pre(n+1);
    for(int i = 1; i <= k; i++) {
        int l,r;
        cin>>l>>r;
        l--,r--;
        pre[r+1] -= 1;
        pre[l] += 1;
    }
    for(int i = 1; i <= n; i++) {
        pre[i] += pre[i-1];
    }

    sort(pre.begin(), pre.begin() + n);
    cout << pre[n/2];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    //cin>>t;
    while(t--)solve();

    return 0;
}

