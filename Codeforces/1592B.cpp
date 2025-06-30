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
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    // for x = n a must be sorted
    // for x = n - 1 can swap only a[0], a[n-1]
    // x = n - 2 a[0],a[n-1]
    // (a[0],a[n-2]), (a[1],a[n-1]) -> a[0],a[1],a[n-2],a[n-1]
    // x = n - 3, (a[0], a[n-1]) (a[0],a[n-2]) (a[0], a[n-3]) (a[1],a[n-2]), (a[1],a[n-1]), (a[2],a[n-1])
    // (a[0],a[1],a[2],a[n-3],a[n-2],a[n-1])
    // x = 1 a[0], a[1], a[1] a[2], a
    vector<int> b = a;
    sort(all(b));
    for(int i = n - x; i <= x - 1; i++) {
        if(a[i] != b[i]) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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

