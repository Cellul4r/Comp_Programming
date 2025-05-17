/* *   author : cellul4r
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
    
    int n,m,p,q;
    cin>>n>>m>>p>>q;

    if(p == 1) {
        if(q * n != m) {
            cout << "NO";
        } else {
            cout << "YES";
        }
        cout << nl;
        return;
    }
    vector<int> ans(n+1);
    
    int sum = 0;
    for(int i = p; i <= n; i += p) {
        ans[i] = q;
        sum += q;
    }

    if(sum == m) {
        cout << "YES" << nl;
        return;
    }

    ans[n] = m - sum;
    for(int i = n - p + 1; i >= 1; i--) {
        int now = 0;
        for(int j = 1; j < p; j++) {
            now += ans[j+i];
        }
        ans[i] = q - now;
        //cerr << now << " " << ans[i] << nl;
    }

    int check = 0;
    for(auto &x : ans) {
        check += x;
        //cerr << x << " ";
    }

    if(check != m) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
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

