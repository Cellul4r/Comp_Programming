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
int n;
void solve(){
    
    cin>>n;
    vector<char> c(n);
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin>>c[i]>>a[i];
    }
    string ans;
    ll cur = 0;
    for(int i = 0; i < n; i++) {
        if(cur + a[i] > 100) {
            cout << "Too Long" << nl;
            return;
        }
        cur += a[i];
        for(int j = 0; j < a[i]; j++) {
            ans += c[i];
        }
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

