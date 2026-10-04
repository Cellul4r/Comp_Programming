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
    vector<int> a(n), b(n), c(n);
    for(auto &x : a) cin>>x;
    for(auto &x : b) cin>>x;
    for(auto &x : c) cin>>x;

    ll cnta = 0, cntc = 0;
    for(int i = 0; i < n; i++) {
        bool ok = true;
        for(int j = 0; j < n; j++) {
            if(b[j] <= a[(i+j)%n]) {
                ok = false;
            }
        }
        if(ok) {
            cnta++;
        }
        ok = true;
        for(int j = 0; j < n; j++) {
            if(b[j] >= c[(i+j)%n]) {
                ok = false;
            }
        }
        if(ok) {
            cntc++;
        }
    }
    cout << cnta * cntc * n << nl;
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

