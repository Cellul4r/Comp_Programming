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
    
    int n,m;
    while(cin>>n>>m) {
        cout << n << " " << m << " ";
        if(n > m) swap(n,m);
        ll cycle = 1;
        for(int i = n; i <= m; i++) {
            ll cnt = 1, tmp = i; 
            while(tmp != 1) {
                cnt++;
                if(tmp & 1) {
                    tmp = tmp * 3 + 1; 
                } else {
                    tmp /= 2;
                }
            }
            cycle = max(cycle, cnt);
        }
        cout << cycle << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

