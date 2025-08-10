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
    int m = 2 * n;
    vector<pi> a;
    for(int i = 0; i < n; i++) {
        int x,y;
        cin>>x>>y;
        if(x > y) swap(x,y);
        a.push_back(make_pair(x,y));
    }
    vector<int> cnt(m+5);
    int want = 1; 
    int mx = 0;
    for(int i = 0; i < n; i++) {
        if((abs(a[i].first - a[i].second) - 1) % 2 == 1) continue;
        int k = (a[i].first + a[i].second) % m;
        cnt[k]++;
    }
    
    for(int i = 0; i < m; i++) {
        if(cnt[i] > mx) {
            mx = cnt[i];
            want = i;
        }
    }
    vector<array<int,3>> ans;
    //cout << want << nl;
    vector<int> save(m), idx(m);
    for(int i = 0; i < n; i++) {
        save[a[i].first] = a[i].second;
        save[a[i].second] = a[i].first;
        idx[a[i].first] = i;
        idx[a[i].second] = i;
    }
    for(int i = 0; i < n; i++) {
        int x = i, y = save[i];
        int now = idx[i]; 
        while((x + y) % m != want) {
            // we must change y to val (pair of x)
            //cerr << x << " HI " << y << nl;
            int val = (want - x + m) % m;
            int xx = (want - y + m) % m;
            int nxt = idx[xx];
            ans.push_back({now,y,val});
            save[x] = val;
            save[val] = x;
            idx[val] = now;
            x = xx;
            y = save[x];
            now = nxt;
        }
    }
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x[0] << " " << x[1] << " " << x[2] << nl;
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

