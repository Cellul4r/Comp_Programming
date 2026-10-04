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
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int ans[N];
void solve(){
    
    int n,m; cin>>n>>m;
    vector<int> a(n+1), cnt(m+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        cnt[a[i]]++;
    }
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for(int i = 1; i <= m; i++) {
        pq.push(cnt[i]);
    }
    int q; cin>>q;
    vector<array<ll,2>> save;
    for(int i = 1; i <= q; i++) {
        ll x; cin>>x;
        save.push_back({x,i});
    }
    sort(all(save));
    ll cur = n;
    vector<int> now;
    while(!pq.empty() && pq.top() == 0) {
        now.push_back(pq.top());
        pq.pop();
    }
    for(auto &xx : save) {
        ll x = xx[0], idx = xx[1];
        if(x <= cur) {
            ans[idx] = a[i];
            continue;
        }
        
    }
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

