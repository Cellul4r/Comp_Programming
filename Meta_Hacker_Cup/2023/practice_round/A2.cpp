#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define L long
#define sLL signed long long
#define ull unsigned long long
#define f first 
#define s second
#define pf printf
#define sf scanf
#define A(a) (a).begin(),(a).end()
using pii = pair<int,int>;
using piL = pair<int,long>;
using pip = pair<int,pair<int,int>>;
const int INF = 1e9;
const int N = 1e5;

ll calc(ll c, ll b) {

    return max(0ll, 2ll*(c/b)-1);
}
void solve() {
    
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans = calc(c,b);
    if(c >= a) {
        ll s = 1;
        ll d = calc(c - a, b);
        ans = max(ans, s+d);
    }
    if(c >= 2*a) {
        ll s = 2;
        ll d = calc(c - 2*a, b);
        ans = max(ans, s+d);
    }
    ll s = c/a;
    c %= a;
    ll d = calc(c,b);
    cout << d << endl;
    cout << s << endl;
    ans = max(ans,s+d);
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;

    for(int i=1;i<=t;++i){
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

