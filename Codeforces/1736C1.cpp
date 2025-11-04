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
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
    }

    // bi >= 1
    // bi+1 >= 2
    // bi+2 >= 3
    // ... bi+j-1 >= i+j
    ll ans = 0;
    for(int i = 0, j = i; i < n; i++) {
        if(j < i) j = i;
        while(j+1 < n && a[j+1] >= (j+1 - i + 1)) {
            j++;
        }

        //cerr << i << " " << j << nl;
        ll k = (j - i + 1);
        ans += k;
        //i = j;
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

