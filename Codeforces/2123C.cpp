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
    vector<int> a(n);
    vector<int> pre(n+1,INF), suff(n+2);
    for(auto &x : a) {
        cin>>x;
    }
    for(int i = 0; i < n; i++) {
        pre[i+1] = min(pre[i], a[i]);
    }
    pre[0] = 0;
    for(int i = n - 1; i >= 0; i--) {
        suff[i+1] = max(suff[i+2], a[i]);
    }
    suff[n+1] = INF;
    string ans;
    for(int i = 0; i < n; i++) {
        bool ok = false;
        if(pre[i+1] == a[i] && suff[i+1] >= a[i]) {
            // do prefix from 0 to i - 1 and then from i + 1 to n - 1
            // then do prefix from
            ok = true;
        } else if(suff[i+1] == a[i] && pre[i+1] <= a[i]) {
            ok = true;
        }
        ans += (ok ? '1' : '0');
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

