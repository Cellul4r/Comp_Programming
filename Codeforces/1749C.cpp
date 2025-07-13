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

int n;
bool check(int x, vector<int>& a) {
    
    multiset<int> now;
    for(auto &y : a) {
        if(y > x) continue;
        now.insert(y);
    }
    for(int i = 1; i <= x; i++) {
        if(now.empty()) {
            return false;
        }
        now.erase(now.find(*now.rbegin()));
        if(!now.empty()) {
            now.erase(now.find(*now.begin()));
        }
        while(!now.empty() && *now.rbegin() > x - i) {
            now.erase(now.find(*now.rbegin()));
        }
    }
    return true;
}
void solve(){
    
    cin>>n;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    int l = 1, r = n;
    int ans = 0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(check(mid,a)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

