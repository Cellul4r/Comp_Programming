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
    vector<int> a, ord;
    a.push_back(0);
    for(int i = 1, now = 0; i <= n; i++) {
        int x;
        cin>>x;
        if(!a.empty() && x == a.back()) continue;
        a.push_back(x);
        ord.push_back(++now);
    }

    sort(all(ord), [&](int i, int j) {
                if(a[i] != a[j]) return a[i] > a[j];
                return i < j; 
            });
    int ans = 1;
    vector<bool> vis(n+2);
    vis[ord[0]] = true;
    for(int i = 1; i < (int)ord.size(); i++) {
        if(!vis[ord[i] - 1] && !vis[ord[i] + 1]) {
            ans++;
        }
        vis[ord[i]] = true;
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

