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
    vector<int> a(n), b(m);

    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    for(int i = 0; i < m; i++) {
        cin>>b[i];
    }

    int j = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] >= b[j]) {
            j++;
        }
    }

    if(j == m) {
        cout << 0 << nl;
        return;
    }
    if(j == m - 1) {
        cout << b[j] << nl;
        return;
    }

    int ans = -1;

    cout << ans << nl;
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

