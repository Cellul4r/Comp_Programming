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
const int N =5e5+5;
const ll INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
ll cnt[N];
ll fact[N];
void solve(){
    
    int n; cin>>n;
    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = fact[i-1] * i % INF;
    }
    vector<int> a(2*n-1);
    for(auto &x : a) {
        cin>>x;
        cnt[x]++;
    }
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        ans = ans * fact[cnt[i] - 1] % INF;
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

