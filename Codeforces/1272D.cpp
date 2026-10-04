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
    vector<int> a(n+2);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    a[n+1] = INT_MAX;
    vector<int> p(n+1,0), s(n+2,0);
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = 1;
        if(a[i] > a[i-1]) {
            p[i] += p[i-1];
        }
        ans = max(ans, p[i]);
    }
    for(int i = n; i >= 1; i--) {
        s[i] = 1;
        if(a[i] < a[i+1]) {
            s[i] += s[i+1];
        }
        ans = max(ans, s[i]);
    }
    for(int i = 1; i <= n; i++) {
        // we remove element a[i]
        // then the j < i will concat j > i
        if(a[i-1] >= a[i+1]) continue;
        ans = max(ans, p[i-1] + s[i+1]);
    }
    cout << ans;
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

