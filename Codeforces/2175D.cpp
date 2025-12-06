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
int n,x;
int a[N];
int recur(int i, int j, int k) {
    if(i == n + 1) {
        return 0;
    }
    int ans = 0;
    ans = max(ans, k + recur(i+1, j, k));
    for(int l = k + 1; l <= a[i] && j + l <= x; l++) {
        ans = max(ans, l + recur(i+1, j + l, l)); 
    }
    return ans;
}
void solve(){
    
    cin>>n>>x;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    int ans = recur(1,0,0);
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

