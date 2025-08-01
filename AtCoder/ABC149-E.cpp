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
int n;
ll m;
vector<ll> a;
vector<ll> pre;
ll ans = 0;
void solve(){
    
    cin>>n>>m;
    a.resize(n);
    pre.resize(n+1);
    for(auto &x : a) {
        cin>>x;
    }
    sort(all(a));
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + a[i-1];
    }
    for(int i = n - 1; i >= 0 && m > 0; i--) {
        ans += 2ll * a[i];
        m--;
        int l = 0, r = i - 1;
        l--;
        while(l < r) {
            int mid = l + (r - l + 1) / 2;
            if((i - mid) * 2ll > m) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        int sz = i - l - 1;
        cerr << l << " " << sz<< nl;
        ans += 2ll * sz * a[i] + 2ll * (pre[i] - pre[l+1]); 
        m -= sz * 2ll;
        cerr << m << nl;
        if(l != -1 && m == 1) {
            ans += a[i] + pre[l+1] - pre[l];
            m = 0;
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

