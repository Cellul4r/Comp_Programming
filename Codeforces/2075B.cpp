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

    vector<ll> a(n);
    for(auto &x : a) cin>>x;
    if(k == 1) {
        ll max_ = 0;
        for(int i = 1; i < n - 1; i++) {
            max_ = max(max_, a[i]);
        }
        cout << max(a[0]+a[n-1], max_ + max(a[0], a[n-1])) << nl;
        return;
    }
    sort(all(a));
    reverse(all(a));
    ll sum = 0;
    for(int i = 0; i <= k; i++) sum += a[i];
    cout << sum << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

