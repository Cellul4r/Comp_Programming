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
    string s;
    cin>>n>>s;

    int sheeps = 0;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        if(s[i] == '*') {
            a.push_back(i);
            sheeps++;
        }
    }

    if(a.empty()) {
        cout << 0 << nl;
        return;
    }
    vector<ll> pre(sheeps+1);
    for(int i = 1; i <= sheeps; i++) {
        pre[i] = a[i-1] + pre[i-1];
    }

    ll ans = LINF;
    for(int i = 0; i < sheeps; i++) {
        ll left = i; 
        ll right = sheeps - i - 1;
        ll k = -pre[i] + pre[sheeps] - pre[i+1] - 1ll * a[i] * (right - left) - left * (left + 1) / 2ll - right * (right + 1) / 2ll;
        ans = min(ans,k);
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

