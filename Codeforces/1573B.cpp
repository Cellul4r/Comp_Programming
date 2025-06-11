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
    vector<int> suff(n+1, INF);
    for(auto &x : a) cin>>x;
    for(int i = 0; i < n; i++) {
        cin>>b[i];
        suff[b[i] / 2 - 1] = i;
    }
    for(int i = n - 1; i >= 0; i--) {
        suff[i] = min(suff[i], suff[i+1]);
        //cerr << suff[i] << " ";
    }
    int ans = INF;
    for(int i = 0; i < n; i++) {
        ans = min(ans, i + suff[a[i] / 2]);
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

