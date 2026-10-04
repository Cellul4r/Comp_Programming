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
    
    int n,d; cin>>n>>d; 
    vector<array<int,2>> cur;
    vector<int> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin>>b[i];
    }
    int run = 0;
    for(int i = 1; i <= n; i++) {
        cur.push_back({a[i],i+d});
        while(b[i] > 0) {
           assert(!cur.empty()); 
           int x = cur[run][0];
           int k = min(x, b[i]);
           x -= k;
           b[i] -= k;
           cur[run][0] = x;
           if(x == 0) run++;
        }
        while(run < (int)cur.size() && cur[run][1] <= i) {
            run++;
        }
    }
    int ans = 0;
    while(run < (int)cur.size()) {
        ans += cur[run][0];
        run++;
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

