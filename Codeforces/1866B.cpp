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
const int N =2e6+1;
const int INF = 998244353;
const ll LINF = 1e18+7;

void solve(){
    
    int n,m;
    cin>>n;
    vector<int> a(N),b(N),c(N),d(N);
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        a[i] = x;
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        b[a[i]] += x;
    }
    cin>>m;
    for(int i = 0; i < m; i++) {
        int x;
        cin>>x;
        c[i] = x;
    }
    for(int i = 0; i < m; i++) {
        int x;
        cin>>x;
        d[c[i]] += x;
    }

    int ans = 1;
    for(int i = 1; i <= N; i++) {
        if(b[i] < d[i]) ans = 0;
        if(b[i] == d[i]) continue;
        else ans *= 2;
        ans %= INF;
    }

    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

