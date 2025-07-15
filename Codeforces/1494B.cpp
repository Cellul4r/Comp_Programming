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
    
    int n, u,r,d,l;
    cin>>n>>u>>r>>d>>l;
    for(int mask = 0; mask < (1 << 4); mask++) {
        int up = 0, right = 0, down = 0, left = 0;
        if(mask & 1) {
            up++;
            left++;
        }
        if(mask & 2) {
            up++;
            right++;
        }
        if(mask & 4) {
            down++;
            left++;
        }
        if(mask & 8) {
            down++;
            right++;
        }
        if(up < u && up + n - 2 >= u) {
            up = u; 
        }
        if(right < r && right + n - 2 >= r) {
            right = r;
        }
        if(down < d && down + n - 2 >= d) {
            down = d;
        }
        if(left < l && left + n - 2 >= l) {
            left = l;
        }
        if(up == u && right == r && down == d && left == l) {
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

