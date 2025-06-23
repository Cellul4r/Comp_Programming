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
    
    int n, m;
    cin>>n>>m;
    vector<int> a(m);
    for(auto &x : a) cin>>x;
    sort(all(a));
    vector<int> groups;
    int ans = 0;
    groups.push_back(n - a[m - 1] + a[0] - 1);
    for(int i = 1; i < m; i++) {
        groups.push_back(a[i] - a[i-1] - 1);
    }
    sort(all(groups), greater<int>());
    for(int i = 0, days = 0; i < (int)groups.size(); i++) {
        //cerr << groups[i] << nl;
        if(groups[i] - 2 * days > 0) {
            ans += max(1, groups[i] - 2 * days - 1);
        }
        days += 2;
        //cerr << groups[i] - 1 - 2 * i << nl;
    }
    cout << n - ans << nl;
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

