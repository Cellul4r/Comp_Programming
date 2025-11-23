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
    
    string s; cin>>s;
    int n = s.length();
    int u = 0, d = 0, l = 0, r = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'U') u++;
        else if(s[i] == 'D') d++;
        else if(s[i] == 'L') l++;
        else if(s[i] == 'R') r++; 
    }
    int x = min(u,d);
    int y = min(l,r);
    if(y == 0) {
        x = min(x,1);
    }
    if(x == 0) {
        y = min(y,1);
    }
    int ans = 2 * x + 2 * y;
    cout << ans << nl;
    for(int i = 0; i < x; i++) {
        cout << 'U';
    }
    for(int i = 0; i < y; i++) {
        cout << 'R';
    }
    for(int i = 0; i < x; i++) {
        cout << 'D';
    }
    for(int i = 0; i < y; i++) {
        cout << 'L';
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

