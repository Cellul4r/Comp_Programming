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
    
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < k && i < n; i++) {
        pq.push(a[i]);
    }
    int idx = k;
    int ans = 0;
    int lastTime = 0;
    while(!pq.empty()) {
        int u = pq.top();
        pq.pop();
        //cout << u << " " << lastTime << nl;
        if(idx < n) pq.push(a[idx]+u);
        idx++;
        ans = max(ans, u - lastTime);
        lastTime = max(lastTime, u);
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

