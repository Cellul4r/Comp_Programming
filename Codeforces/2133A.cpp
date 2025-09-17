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
    vector<int> a(n);
    for(auto &x : a) cin>>x;
    // x/y*z
    // 2nd k = a[1]/a[0] * 1
    // 3rd k = a[2]/a[1] * (a[1] / a[0] * 1)
    // k = a[2] / a[0] * 1
    sort(all(a));
    for(int i = 0; i < n -1; i++) {
        if(a[i] == a[i+1]) {
            cout << "YES" << nl;
            return;
        }
    }
    cout << "NO" << nl;
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

