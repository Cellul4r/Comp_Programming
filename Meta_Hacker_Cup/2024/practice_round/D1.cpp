#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define L long
#define sLL signed long long
#define uLL unsigned long long
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

void solve() {
    
    int n;
    ll g;
    cin>>n>>g;
    vector<pair<ll,int>> now;
    for(int i=1;i<=n;++i) {
        ll e;
        cin>>e;
        now.push_back({e,i});
    }
    sort(A(now));
    reverse(A(now));
    
    ll ans = LLONG_MAX;
    int idx = INF;
    for(int i=0;i<n;++i) {
        if(ans > abs(g - now[i].f)) {
            ans = abs(g - now[i].f);
            idx = i;
        }
        //cout << x.f << " TEST " << x.s << endl;

    }
    cout << idx + 1 << " " << ans << endl;
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

