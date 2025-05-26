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
    
    int n;
    cin>>n;
    vector<int> a(n);
    deque<int> dq;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        a[i] = x;
        dq.push_back(x);
    }
    
    // a is sorted
    int ans = 1;
    while((int)dq.size() >= 2) {
        int u = dq.front();
        dq.pop_front();
        int v = dq.front();
        dq.pop_front();
        //cerr << u << " " << v << nl;
        if(u + 1 >= v) {
            dq.push_front(u);
        } else {
            ans++;
            dq.push_front(v);
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

