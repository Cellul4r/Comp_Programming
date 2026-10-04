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
    
    // alice must fast do convert all to 1.1.1........
    // otherwise 1 0 1 .... then bob choose all the array then min = 0 convert to 1 Bob win
    // if all 1 then alice
    int n; cin>>n;
    vector<int> a(n);
    int l = INF, r = -1;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        if(a[i] == 0) {
            l = min(l,i);
            r = max(r,i);
        }
    }
    if(r == -1) {
        cout << "Alice" << nl;
        return;
    }
    cout << (l == 0 && r == n -1 ? "Bob" : "Alice") << nl; 
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

