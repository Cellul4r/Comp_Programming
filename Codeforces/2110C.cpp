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
    
    int n;
    cin>>n;
    vector<pi> b(n);
    vector<int> suff(n+1),a(n);
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i =0;i<n;i++) {
        cin>>b[i].first>>b[i].second;
    }
    suff[n] = INF;
    for(int i = n-1;i>=0;i--) {
        if(a[i] != 1) suff[i] = min(suff[i+1], b[i].second);
        else suff[i] = min(suff[i+1] - 1, b[i].second - 1);
    }
    vector<int> ans(n);
    int now = 0;
    for(int i = 0; i < n; i++) {
        int l = b[i].first, r = b[i].second;
        if(a[i] != -1) {
            now += a[i];
            ans[i] = a[i];
        } else if(suff[i] >= now+1 && suff[i] != INF) {
            ans[i] = 1;
            now++;
        } else {
            ans[i] = 0;
        }
        //cerr << now << nl;
        if(now < l || now > r) {
            cout << -1 << nl;
            return;
        }
    }
    now = 0;
    for(int i =0;i<n;i++) {
        int l = b[i].first, r = b[i].second;
        now += ans[i];
        if(now < l || now > r) {
            assert(false);
        }
    }
    for(int i=0;i<n;i++) cout << ans[i] << " ";
    cout << nl;
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

