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
int a[10001];
int maxR = 0;
void solve(){

    int l,r,h;
    while(cin>>l>>h>>r) {
        maxR = max(maxR, r);
        for(int j = l; j < r; j++) {
            a[j] = max(a[j], h);
        }
    }

    for(int i = 1; i < maxR; i++) {
        if(a[i] != a[i-1]) {
            cout << i << " " << a[i] << " ";
        }
    }
    cout << maxR << " " << 0 << nl;
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

