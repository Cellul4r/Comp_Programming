/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e2+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n;
long double r;
array<long double,3> a[N];
long double ans = 0;
long double pi = (long double)acos(-1);
void solve(){

    cin>>n>>r;
    for(int i = 0; i < n; i++) {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }

    for(int i = 0; i < n; i++) {
        ans += pi * 4.0 * r * r * r / 3.0; 
        int j = (i + 1) % n;
        long double d = sqrtl((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1])+(a[i][2]-a[j][2])*(a[i][2]-a[j][2]));
        ans -= pi * 2.0 * (r - d / 2.0) * (r - d / 2.0) * (2.0 * r + d / 2.0) / 3.00;
    }

    cout << fixed << setprecision(10) << ans << nl;
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

