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
    
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(k), b(k);
    vector<int> cntA(n+1), cntB(m+1);
    map<pi,int> cnt;
    for(int i = 0; i < k; i++) {
        cin>>a[i];
        cntA[a[i]]++;
    }
    for(int i = 0; i < k; i++) {
        cin>>b[i];
        cntB[b[i]]++;
        cnt[make_pair(a[i],b[i])]++;
    }

    ll ans = 0;
    for(int i = 0; i < k; i++) {
        ll x = cntA[a[i]] + cntB[b[i]] - cnt[make_pair(a[i],b[i])];
        //cerr << x << nl;
        ans += k - x;
    }
    cout << ans / 2ll << nl;
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

