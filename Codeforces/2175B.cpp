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
    
    int n,l,r;
    cin>>n>>l>>r;
    vector<int> ans(n+1);
    for(int i = 1; i <= n; i++) {
        int x,y;
        if(i == r) {
            y = l - 1;
        } else {
            y = i;
        }

        if(i - 1 == r) {
            x = l - 1;
        } else {
            x = i - 1;
        }
        ans[i] = x ^ y;
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << nl;
    /*for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            int now = 0;
            for(int k = i; k <= j; k++) {
                now ^= ans[k];
            }
            if(i == l && j == r) {
                if(now != 0) {
                    cout << "NOPE\n" << i << " " << j << nl;
                }
            } else if(now == 0) {
                cout << "NOPE2\n" << i << " " << j << nl;
            }
        }
    }*/
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

