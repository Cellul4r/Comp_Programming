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
    vector<int> a(n), b(n);
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        sum += a[i];
        b[i] = i;
    }
    sort(all(b), [&](int i, int j) {
                return a[i] < a[j];
            });
    vector<int> ans, dp(n);
    dp[n-1] = 1;
    ll cur = sum;
    for(int i = n - 2; i >= 0; i--) {
        cur -= a[b[i+1]];
        if(cur >= a[b[i+1]]) {
            dp[i] = dp[i+1];
        } else {
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(dp[i] == 1) {
            ans.push_back(b[i]);
        }
    }
    sort(all(ans));
    cout << ans.size() << nl;
    for(auto &x : ans) {
        cout << x + 1 << " ";
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

