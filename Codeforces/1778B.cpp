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
    
    int n,m,d;
    cin>>n>>m>>d;
    // rip problem! scary! T-T
    vector<int> pos(n+1), a(m);
    for(int i = 0; i < n; i++) {
        int x; cin>>x;
        pos[x] = i;
    }
    for(auto &x : a) cin>>x;
    int ans = INF;
    for(int i = 0; i < m - 1; i++) {
        int x = a[i], y = a[i+1];
        if(pos[y] < pos[x] || pos[y] > pos[x] + d) {
            ans = 0;
            break;
        }
        ans = min(ans, pos[y] - pos[x]);
        if(pos[x] + n - pos[y] - 1 > d + pos[x] - pos[y]) {
            ans = min(ans, d + pos[x] - pos[y] + 1);
        }
    }
    cout << ans << nl;
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

