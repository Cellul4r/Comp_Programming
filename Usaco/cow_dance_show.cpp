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
    
    int n,t;
    cin>>n>>t;
    vector<int> a(n);
    for(auto &x : a) cin>>x;

    auto f = [&](int x) {
        int now = 0;        
        priority_queue<int, vector<int>, greater<int>> Q;
        for(int i = 0; i < x; i++) Q.push(a[i]);
        int idx = x;
        while(idx < n) {
            int u = Q.top();
            Q.pop();
            now = max(now,u);
            Q.push(u + a[idx++]);
        }
        while(!Q.empty()) {
            int u = Q.top();
            Q.pop();
            now = max(now, u);
        }
        return now <= t;
    };

    int l = 1, r = n;
    r++;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if(f(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    setIO("cowdance");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

