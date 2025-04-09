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
    vector<ll> a(2*n);
    set<ll> cnt;
    for(int i=0;i<2*n;i++) {
        cin>>a[i];
        cnt.insert(a[i]);
    }
    sort(all(a));
    reverse(all(a));
    
    ll ans = a[0] + a[1];
    // the missing is a[2]
    for(int i = 2; i < 2 * n; i++) {
        ans += ((i & 1) ? 1 : -1) * a[i];
    }

    cout << a[0] << " " << ans << " ";
    for(int i = 1; i < 2 * n; i++) {
        cout << a[i] << " ";
    }
    cout << nl;
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

