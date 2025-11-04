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
    
    int n,m; cin>>n>>m;
    string s; cin>>s;
    vector<int> a(m);
    for(auto &x : a) cin>>x;
    int cur = 0;
    int j = 1;
    while(cur < m && a[cur] == j) {
        cur++;
        j++;
    }
    vector<int> ans;
    if(a[0] == 1) {
        ans.push_back(1);
    }
    for(auto &x : s) {
        now++;
        if(x == 'A') {
        } else {
            while(cur < m && a[cur] == now) {
                ans.push_back(now);
                cur++;
                now++;
            }
            ans.push_back(now);
        }
    }
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x << " ";
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

