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
    
    int m; cin>>m;
    string s[2];
    cin>>s[0]>>s[1];
    int cur = -1;
    auto f = [&](int i) {
        if(i >= m) {
            return 2;
        }
        if(s[0][i] == s[1][i]) return 2;
        if(s[0][i] == 'B') return 0;
        return 1;
    };
    for(int i = 0; i < m; i++) {
        int type = f(i);
        //cerr << i << " " << cur << nl;
        if(type == 2) {
            if(cur == -1 && f(i+1) != 2) {
                cur = f(i+1);
            } else if(cur != -1) {
                cur ^= 1;
            }
        } else {
            if(cur != -1 && cur != type) {
                cout << "NO" << nl;
                return;
            }
            cur = type;
        }
    }
    cout << "YES" << nl;
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

