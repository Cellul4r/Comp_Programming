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
    vector<ll> a(n+1), pre(n+1);
    ll ans = 0, sum = 0;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        sum += a[i];
    }
    
    ans = sum;
    // find range(l,r) to do 1 operation replace with l + r
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i-1] + a[i];
    }
    vector<ll> preL(n+1), suffR(n+1);
    for(ll i = 1; i <= n; i++) {
        preL[i] = max(preL[i-1],pre[i-1] + i - i * i);
        suffR[i] = i * i + i - pre[i];
    }
    for(int i = n - 1; i >= 1; i--) {
        suffR[i] = max(suffR[i],suffR[i+1]);
    }

    for(int i = 1; i <= n; i++) {
        ans = max(ans, sum + preL[i] + suffR[i]);
    }
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

