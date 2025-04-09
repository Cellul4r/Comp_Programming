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
    
    int n,m;
    cin>>n>>m;

    int now = m - 1;
    if(m == 1) {
        cout << 0 << nl;
    } else if(n < m - 1) {
        cout << n + 1 << nl;
    } else {
        cout << m << nl;
    }
    for(int i = 1; i <= min(n,m - 1); i++) {
        int k = now;
        for(int j = 1; j <= m; j++) {
            cout << k << " ";
            k--;
            k += m;
            k %= m;
        }
        cout << nl;
        now--;
    }

    now++;
    now %= m;
    for(int i = 1; i <= max(0,n - m + 1); i++) {
        int k = now;
        for(int j = 1; j <= m; j++) {
            cout << k << " ";
            k--;
            k += m;
            k %= m;
        }
        cout << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

