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
    
    int n;
    cin>>n;
    map<int,int> cnt;
    priority_queue<pi> pq;
    for(int i = 0; i < n; i++) {
        int x;
        cin>>x;
        cnt[x]++;
    }
    for(auto &[x,y] : cnt) {
        pq.push(make_pair(y,x));
    }
    while(pq.size() >= 2) {
        int u = pq.top().second, w1 = pq.top().first;
        pq.pop();
        int v = pq.top().second, w2 = pq.top().first;
        pq.pop();
        w1--;
        w2--;
        if(w1 > 0) {
            pq.push(make_pair(w1,u));
        }
        if(w2 > 0) {
            pq.push(make_pair(w2,v));
        }
    }
    int ans = 0;
    while(!pq.empty()) {
        ans += pq.top().first;
        pq.pop();
    }
    cout << ans << nl;
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

