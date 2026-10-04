/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n;
    ll k; cin>>n>>k;
    string s; cin>>s;
    int one = 0;
    vector<int> ans(n, 1);
    int zero = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '1') {
            one++;
            continue;
        }
        // 0
        ans[i] = 0;
        if(k >= one) {
            ans[i] = 1;
            ans[zero] = 0;
            k -= one;
        } else {
            // k < one can't make any more greate operation for the next turn
            ans[i] = 1;
            ans[i - k] = 0;
            k = 0;
        }
        zero++;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i];
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

