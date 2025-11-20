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
int depth[N], a[N];;
int n;
void recur(int l, int r, int d) {
    if(l > r) return;
    int mx = -1, idx = -1;
    for(int i = l; i <= r; i++) {
        if(a[i] > mx) {
            mx = a[i];
            idx = i;
        }
    }

    depth[mx] = d;
    recur(l,idx-1,d+1);
    recur(idx+1,r,d+1);
}
void solve(){
    
    cin>>n;
    for(int i = 0; i < n; i++) depth[i] = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        a[i]--;
    }

    recur(0,n-1,0);
    for(int i = 0; i < n; i++) cout << depth[a[i]] << " ";
    cout << nl;
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

