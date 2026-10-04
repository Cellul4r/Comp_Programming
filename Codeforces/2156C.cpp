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
    
    int n,k; cin>>n>>k;
    vector<int> p(n+1), pre(n+1);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        p[x]++;
    }

    for(int i = 1; i <= n; i++) {
        pre[i] = p[i] + pre[i-1];
    }

    int cur = 0;
    int ans = 1;
    for(int i = 1; i <= n && cur <= k; i++) {
        int now = pre[min(n,2*i-1)] - pre[i] + pre[min(n,4*i-1)] - pre[min(n,2*i)];
        if(3*i <= n) now -= p[3*i];
        //cerr << i << " " << now << " " << cur << nl;
        if(cur + now <= k) {
            ans = i;
        }
        cur += p[i];
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

