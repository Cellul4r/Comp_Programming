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
    
    int n,q; cin>>n>>q;
    vector<array<int,2>> a(n+1);
    vector<int> b,c;
    for(int i = 1; i <= n; i++) {
        int l,r,y;
        cin>>l>>r>>y;
        a[i] = {l,r};
        b.push_back(r);
        c.push_back(l);
    }
    sort(all(b)); // find min r
    sort(all(c)); // find max l
    for(int i = 0; i < q; i++) {
        int x; cin>>x;
        int ans = 0;
        if(b[0] < x) {
            ans = max(ans,x - b[0]);
        }
        if(c[n-1] > x) {
            ans = max(ans, c[n-1] - x);
        }
        cout << ans << nl;
    }
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

