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
    
    int n,x,y;
    cin>>n>>x>>y;
    multiset<int> now;
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        now.insert(x);
    }

    if(x > y) {
        cout << n;
        return;
    }

    int me = 1;
    int ans = 0;
    while(!now.empty()) {
        auto it = now.upper_bound(x);
        if(it != now.begin()) {
            it--;
            now.erase(it);
            if(me) ans++;
        } else {
            break;
        }
        me ^= 1;
    }
    cout << ans;
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

