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
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
ll fact[N];
void solve(){
    
    int n;
    cin>>n;
    vector<int> a(n);
    int val, cnt = 0;
    for(auto &x : a) {
        cin>>x;
    }
    val = a[0];
    for(int i = 1; i < n; i++) val = val & a[i];
    for(int i = 0; i < n; i++) {
        if(a[i] == val) cnt++;
    }
    if(cnt < 2) {
        cout << 0 << nl;
        return;
    }
    cout << (fact[n-2] * cnt % INF) * (cnt - 1) % INF << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    fact[0] = 1;
    for(int i = 1; i < N; i++) fact[i] = fact[i-1] * i % INF;
    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

