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
    vector<array<ll,2>> a(n);
    for(int i = 0; i < n; i++) {
        ll x; cin>>x;
        a[i] = {x,i+1};
    }

    vector<int> ans(n+1,-1);
    for(int i = 0; i < n; i++) {
        for(int j = i - 1; j >= 0; j--) {
            if(a[j][0] > a[i][0]) {
                ans[i+1] = j+1;
                break;
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << nl;
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

