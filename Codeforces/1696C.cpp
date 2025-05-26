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
    
    int n,m,k;
    cin>>n>>m;
    deque<pi> a,b;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        int now = 1;
        while(x % m == 0) {
            x /= m;
            now *= m;
        }
        a.push_back(make_pair(x,now));
    }
    
    cin>>k;
    for(int i = 0; i < k; i++) {
        int x;
        cin>>x;
        int now = 1;
        while(x % m == 0) {
            x /= m;
            now *= m;
        }
        b.push_back(make_pair(x,now));
    }

    while(!a.empty() && !b.empty()) {
        auto x = a.front(), y = b.front();
        if(x.first != y.first) {
            cout << "NO" << nl;
            return;
        }
        a.pop_front();
        b.pop_front();
        int now = min(x.second, y.second);
        x.second -= now;
        y.second -= now;
        if(x.second != 0) a.push_front(x);
        if(y.second != 0) b.push_front(y);
    }

    if(!a.empty() || !b.empty()) {
        cout << "NO" << nl;
        return;
    }
    cout << "YES" << nl;
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

