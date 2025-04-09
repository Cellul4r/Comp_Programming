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
    ll x;
    cin>>n>>x;
    vector<ll> a(n);
    for(auto &x : a) cin>>x;
    sort(all(a));
    reverse(all(a));
    int ans = 0;
    int i = 0;
    while(i < n) {
        //cerr << i << nl;
        ll now = 0, k = 0;
        while(i < n && now * k < x) {
            now = a[i++];
            k++;
        }
        if(now * k >= x) ans++;
    }
    cout << ans << nl;
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

