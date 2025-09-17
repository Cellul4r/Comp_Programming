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

    // y = x * 10 ^ k
    // n = x + y
    // n = x + x * 10^k
    // n = x * (1 + 10^k)
    // n = x * 10...1

    ll n; cin>>n;
    // x = 1 -> 10 100 1000 -> 11 101 1001
    // 2 -> 12 102 1002
    ll cur = 1;
    vector<ll> ans;
    for(int i = 1; i <= 18; i++) {
        cur *= 10ll;
        if(n % (cur + 1) == 0) {
            ans.push_back(n / (cur + 1));
        }
    }
    sort(all(ans));
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

