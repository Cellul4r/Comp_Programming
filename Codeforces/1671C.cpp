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
    
    int n,x;
    cin>>n>>x;
    ll sum = 0;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
        sum += x;
    }

    ll ans = 0;
    sort(all(a));
    ll prev_ = 0;
    for(int i = n - 1; i >= 0; i--) {
        // sum + k > x
        // k > x - sum
        // k = x - sum + 1
        if(x < sum) {
            sum -= a[i];
            continue;
        }
        ll k = max(0ll,(x - sum)) / (i+1) + 1;
        ans += max(0ll, (k - prev_) * (i + 1));
        prev_ = k;
        sum -= a[i];
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

