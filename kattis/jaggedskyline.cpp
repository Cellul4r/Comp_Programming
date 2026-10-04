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
string ask(ll i, ll j) {
    cout << "? " << i << " " << j << endl;
    cout.flush();
    string ans;
    cin>>ans;
    return ans;
}
void solve(){
    
    ll w,h;
    cin>>w>>h;
    set<int> now;
    for(int i = 1; i <= w; i++) now.insert(i);
    ll l = 0, r = h;
    int op = 0;
    ll ans = -1;
    while(l <= r) {
        ll mid = l + (r - l) / 2ll;
        set<int> tmp;
        for(auto &x : now) {
            if(ask(x, mid) == "building") {
                assert(op <= 11000-1);
                op++;
                tmp.insert(x);
            }
        }
        if(tmp.empty()) {
            r = mid - 1;
        } else {
            ans = mid;
            l = mid + 1;
            now = tmp;
        }
    }
    assert(!now.empty());

    cout << "! " << *now.begin() << " " << ans << endl;
    cout.flush();
}

int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
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

