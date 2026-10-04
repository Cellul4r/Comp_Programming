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
    
    int n,m,k;
    cin>>n>>m>>k;
    vector<ll> a(n);
    ll sum = 0;
    for(auto &x : a) {
        cin>>x;
        sum += x;
    }
    sort(all(a), greater<ll>());
    
    double ans = 0;
    for(int i = 0; i < m + k && i < n; i++) {
        ans += a[i]; 
    }
    ans /= sum;
    ans *= 100;
    cout << fixed << setprecision(8) << ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

