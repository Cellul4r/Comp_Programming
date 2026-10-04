/*
 * author : cellul4r
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
const int N =2e5+10;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);

void solve(){
    int n; 
    cin >> n;
    
    vector<int> p(n + 1);
    vector<int> depth(n + 1, 0);
    vector<int> max_d(n + 1, 0);
    vector<int> max1(n + 1, -1);
    vector<int> max2(n + 1, -1);
    
    for(int i = 2; i <= n; i++) {
        cin >> p[i];
        depth[i] = depth[p[i]] + 1;
        max_d[i] = depth[i];
    }
    
    for (int i = n; i >= 2; i--) {
        int parent = p[i];
        int d = max_d[i];
        
        if (d > max_d[parent]) {
            max_d[parent] = d;
        }
        
        if (d >= max1[parent]) {
            max2[parent] = max1[parent];
            max1[parent] = d;
        } else if (d > max2[parent]) {
            max2[parent] = d;
        }
    }
    
    ll distinct_guilds = n; 
    for (int i = 1; i <= n; i++) {
        if (max2[i] != -1) {
            distinct_guilds += (max2[i] - depth[i]);
        }
    }
    
    cout << distinct_guilds << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    cin >> t;
    while(t--) solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}
