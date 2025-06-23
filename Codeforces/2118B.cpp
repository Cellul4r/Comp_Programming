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

    vector<array<int,3>> ans;
    ans.push_back({1,1,n});
    for(int i = 2; i <= n; i++) {
        ans.push_back({i,1,n-i+1});

        ans.push_back({i,n-i+2,n});
    }
    assert((int)ans.size() <= 2 * n);
    cout << ans.size() << nl;
    for(auto &[x,y,z] : ans) {
        cout << x << " " << y << " " << z << nl;
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

