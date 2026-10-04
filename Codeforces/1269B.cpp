/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    // there must exist i in ai such that in the future or right now ai = b[0]
    // a and b is sorted array
    int n,m; cin>>n>>m;
    deque<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>b[i];
    }
    sort(all(a));
    sort(all(b));
    int ans = m;
    for(int i = 0; i < n; i++) {
        bool ok = true;
        int cur = (m - (a[0] - b[0])) % m;
        for(int j = 0; j < n; j++) {
            int diff = (m - (a[j] - b[j])) % m; 
            if(cur != diff) {
                ok = false;
                break;
            }
        }
        if(ok) {
            ans = min(ans, cur);
        }
        // leftshift the array a
        a.push_back(a[0]);
        a.pop_front();
    }
    cout << ans << nl;
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

