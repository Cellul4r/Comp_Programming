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
    
    int n,m; cin>>n>>m;
    int ans = m;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i]>>b[i];
    }

    int last = 0, zone = 0;
    for(int i = 1; i <= n; i++) {
        int k = a[i] - last;
        if(k % 2 == 1 && b[i] == zone) {
            ans--; 
        } else if(k % 2 == 0 && b[i] != zone) {
            ans--;
        }
        last = a[i];
        zone = b[i];
    }
    cout << ans << nl;
    // 0 0
    // 1 0
    // 2 0
    // 3 1
    // 4 0
    // 5 1
    // 6 1
    // 7 ?
    // 8 ?
    // 9 0
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

