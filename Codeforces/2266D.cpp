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
    
    int n; cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        a[i] -= i;
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    int ans = 0;
    int cur = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i-1] + 1) {
            cur++;
        } else {
            ans = max(ans, cur);
            cur = 1;
        }
    }
    ans = max(ans, cur);
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

