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
int n;
double dist(pi p, pi q) {
    return sqrt(pow(p.first - q.first,2) + pow(p.second - q.second,2));
}

double dp[(1<<16)];
bool vis[(1<<16)];
double recur(int mask, vector<pi>& a) {
    if(mask == (1 << n) - 1) return 0.0;
    if(vis[mask]) return dp[mask];
    double ans = INF;
    for(int i = 0; i < (int)a.size(); i++) {
        if((1 << i) & mask) continue;
        for(int j = i + 1; j < (int)a.size(); j++) {
            if((1 << j) & mask) continue;
            int nmask = mask ^ (1 << i);
            nmask = nmask ^ (1 << j);
            double k = dist(a[i],a[j]);
            ans = min(ans, k + recur(nmask,a));
        }
    }
    vis[mask] = true;
    return dp[mask] = ans;
}
void solve(){
    
    n *= 2;
    for(int i = 0; i < (1<<n); i++) vis[i] = false;
    vector<pi> a(n);
    vector<bool> vis(n);
    for(auto &x : a) {
        string s;
        cin>>s;
        cin>>x.first>>x.second;
    }

    cout << fixed << setprecision(2) << recur(0,a) << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>n;
    while(n != 0) {
        cout << "Case " << t++ << ": ";
        solve();
        cin>>n;
    }

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

