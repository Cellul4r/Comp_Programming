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
    
    int n,q; cin>>n>>q;
    vector<int> a(n);
    for(auto &x : a) {
        cin>>x;
        assert(x == 0 || x == 1);
    }

    vector<int> idx(n), preA(n+1), preB(n+1);
    for(int i = 1; i <= n; i++) {
        preA[i] = preA[i-1] + (a[i-1] == 0);
    }
    for(int i = 1; i <= n; i++) {
        preB[i] = preB[i-1] + (a[i-1] == 1);
    }

    for(int i = 0; i < n;) {
        int j = i+1;
        while(j < n && a[j] != a[j-1]) {
            j++;
        }

        for(int k = i; k < j; k++) {
            idx[k] = j-1;
        }
        i = j; 
    }

    for(int k = 0; k < q; k++) {
        int l, r;
        cin>>l>>r;
        l--,r--; 
        bool ok = true;
        int x = preA[r+1] - preA[l];
        int y = preB[r+1] - preB[l];
        if(x % 3 != 0) ok = false;
        if(y % 3 != 0) ok = false;
        if(!ok) {
            cout << -1 << nl;
            continue;
        }
        int ans = x / 3 + y / 3 + (r <= idx[l]);
        cout << ans << nl;
    }
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

