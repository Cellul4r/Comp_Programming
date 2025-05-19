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

void solve(){
    
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int nn = n, mm = m;
    int ans = INF;
    int play = 0;
    if(n != 1) {
        play++;
        n = min(n - a + 1, a);
    }
    while(n != 1 || m != 1) {
        play++;
        if(n != 1) {
            n = (n + 1) / 2;
            continue;
        }
        m = (m + 1) / 2;
    }
    ans = min(ans, play);
    play = 0;
    n = nn, m = mm;
    if(m != 1) {
        play++;
        m = min(m - b + 1, b);
    }
    while(n != 1 || m != 1) {
        play++;
        if(n != 1) {
            n = (n + 1) / 2;
            continue;
        }
        m = (m + 1) / 2;
    }
    ans = min(ans, play);
    cout << ans << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    cin>>t;
    while(t--)solve();

    return 0;
}

