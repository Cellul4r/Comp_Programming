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
    // 3(8), 4(9), 5(10), 11(11)
    // 1(2), 1(3)
    // 1+1, 1+2
    // 4 1 4 9 5
    //  +3     +4
    int mx = 0;
    int k = 0;
    for(auto &x : a) {
        if(x < mx) {
            k = max(k, mx - x);
        } else {
            mx = x;
        }
    }
    mx = 0;
    for(auto &x : a) {
        if(x < mx) {
            x += k;
            mx = max(mx, x + k);
        } else {
            mx = x;
        }

    }
    for(int i = 1; i < n; i++) {
        if(a[i] < a[i-1]) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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

