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
    
    int n; cin>>n;
    if(n % 2 == 0) {
        cout << "NO" << nl;
        return;
    }

    vector<int> ans(2*n);
    for(int i = 0, cur = 1; i < n; i++, cur += 2) {
        if(i % 2 == 0) {
            ans[i] = cur;
            ans[i+n] = cur+1;
        } else {
            ans[i] = cur + 1;
            ans[i+n] = cur;
        }
    }
    cout << "YES" << nl;
    for(auto &x : ans) {
        cout << x << " ";
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

