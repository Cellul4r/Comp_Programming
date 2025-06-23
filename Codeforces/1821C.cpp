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

    string s;
    cin>>s;
    int n = s.length();
    int lg = 0;
    while((1 << (lg+1)) <= n) lg++;
    for(int i = 0; i < lg; i++) {
        char c = s[0];
        bool ok = true;
        for(int j = 0; j < n; j += (1 << i)) {
            if(c != s[j]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << i << nl;
            return;
        }
        if(i == 0) continue;
        c = s[1];
        ok = true;
        for(int j = 1; j < n; j += (1 << i)) {
            if(c != s[j]) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << i << nl;
            return;
        }
    }
    cout << lg << nl;
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

