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
    
    vector<int> a(3);
    cin>>a[0]>>a[1]>>a[2];
    sort(all(a));

    // minimum possible just move to them as fast as possible
    // if there are 2 locations such that consecutives then just move another one to
    // using 1 move only
    if(a[2] - a[1] == 1 && a[1] - a[0] == 1) {
        cout << 0;
    } else if(a[2] - a[1] == 2 || a[1] - a[0] == 2) {
        cout << 1;
    } else {
        cout << 2;
    }
    cout << nl;
    cout << max(a[2] - a[1], a[1] - a[0]) - 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

