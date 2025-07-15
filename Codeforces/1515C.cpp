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
    
    int n,m,x;
    cin>>n>>m>>x;
    vector<int> a(n), ind(n);
    for(auto &x : a) {
        cin>>x;
    }
    for(int i = 0; i < n; i++) ind[i] = i;
    sort(all(ind), [&](int i, int j) {
                return a[i] > a[j];
            });
    vector<int> ans(n), height(m);
    int mx;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for(int i = 0; i < m; i++) {
        ans[ind[i]] = i;
        height[i] = a[ind[i]];
        pq.push(make_pair(height[i],i));
    }
    mx = height[0]; 
    for(int i = m; i < n; i++) {
        // assign each block to some tower
        int k = pq.top().second, h = pq.top().first; 
        if(abs(mx - h - a[ind[i]]) > x) {
            cout << "NO" << nl;
            return;
        }
        ans[ind[i]] = k;
        mx = max(mx, h + a[ind[i]]);
        pq.pop();
        pq.push(make_pair(h + a[ind[i]], k));
    }
    cout << "YES" << nl;
    for(auto &x : ans) {
        cout << x + 1 << " ";
    }
    cout << nl;
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

