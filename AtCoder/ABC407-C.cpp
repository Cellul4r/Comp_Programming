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

string s;
void solve(){

    cin>>s;
    int n = s.length();
    ll ans = 0;
    ll now = 0;
    for(int i = n-1; i >= 0; i--) {
        ll x = s[i] - '0'; 
        if(now >= x) {
            x = now - x;
            x = 10 - (x % 10);
            if(x == 10) x = 0;
            /*while(x > 10) {
                x -= 10;
            }
            x = 10 - x;*/
        } else {
            x -= now;
        }
        //cerr << s[i] << " " << x << " " << now << nl;
        ans += x + 1;
        now += x;
    }
    cout << ans;
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

    //cin>>t;
    while(t--)solve();

    return 0;
}

