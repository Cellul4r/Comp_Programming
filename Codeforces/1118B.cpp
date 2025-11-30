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
    
    int n; cin>>n;
    vector<int> a(n+1);
    int even = 0, odd = 0;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        if(i & 1) {
            odd += a[i];
        } else {
            even += a[i];
        }
    }

    int cur1 = 0, cur2 = 0;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(i & 1) {
            odd -= a[i];
        } else {
            even -= a[i];
        }
        if(cur1 + even == cur2 + odd) {
            ans++;
        }
        if(i & 1) {
            cur1 += a[i];
        } else {
            cur2 += a[i];
        }

    }
    cout << ans;
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

