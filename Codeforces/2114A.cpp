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
    
    string s;
    cin>>s;
    int val = 0;
    for(int i = 0; i < (int)s.length(); i++) {
        val = val * 10 + (s[i] - '0');
    }
    for(int a = 0; a <= 100; a++) {
        for(int b = 0; b <= 100; b++) {
            if((a + b) * (a + b) == val) {
                cout << a << " " << b << nl;
                return;
            }
        }
    }
    cout << -1 << nl;
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

