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
    if(n == 1) {
        cout << "1 1" << nl;
        cout << "1 1 1" << nl;
        return;
    }
    vector<vector<int>> ans;

    ll sum = 0;
    for(int i = 1, cur = 1; i <= n; i++, cur += 2) {
        sum += 1ll * i * cur;
    }

    for(int i = n; i >= 1; i--) {
        vector<int> now{1,i};
        for(int j = 1; j <= n; j++) {
            now.push_back(j);
        }
        ans.push_back(now);
        now.clear();
        now = {2,i};
        for(int j = 1; j <= n; j++) {
            now.push_back(j);
        }
        ans.push_back(now);
    }
    assert((int)ans.size() <= 2 * n);
    cout << sum << " " << ans.size() << nl;
    for(auto &x : ans) {
        for(auto &y : x) {
            cout << y << " ";
        }
        cout << nl;
    }
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

