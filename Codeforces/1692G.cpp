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
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }
    int ans = 0;
    vector<ll> pre(n+1);
    for(int i = 1; i < n; i++) {
        if(a[i] <= a[i-1]) {
            if(a[i] * 2 > a[i-1]) {
                pre[i] = 1;
            } else {
                pre[i] = k+1;
            }
        }
        //cerr << pre[i] << nl;
    }
    for(int i = 1; i <= n; i++) {
        pre[i] += pre[i-1];
    }
    for(int i = 0; i < n - k; i++) {
        if(pre[i+k] - pre[i] <= k) {
            //cerr << "CHECK: " << i << nl;
            ans++;
        }
    }
    cout << ans << nl;
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

    cin>>t;
    while(t--)solve();

    return 0;
}

