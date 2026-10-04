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
    
    // n = 2 -> 8 -> [1,2,1,1,2,2,1,2]
    // n = 3 -> 12 -> [1,2,3,1,1,3,3,2,2,1,2,3]
    // n = 4 -> 16 -> [1,2,3,4,1,1,3,3,2,2,4,4,1,2,3,4]
    int n; cin>>n;
    for(int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    for(int i = 1; i <= n; i += 2) {
        cout << i << " " << i << " ";
    }
    for(int i = 2; i <= n; i += 2) {
        cout << i << " " << i << " ";
    }
    for(int i = 1; i <= n; i++) {
        cout << i << " ";
    }
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

