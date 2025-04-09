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
    ll ans = 0;
    while(n > 0) {
        if(n & 1) {
            ans++;
            n -= k;
            k = min(k,n+1);
            if(n > 0) {
                ans += n / (k - 1);
                n = n % (k - 1);
                k = min(k, n+1);
            }
        } else {
            ans += n / (k - 1);
            n = n % (k - 1);
            k = min(k, n+1);
        }
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

