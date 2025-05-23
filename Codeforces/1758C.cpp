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

void test(int n, int x) {

    vector<int> a(n);
    iota(all(a), 1);
    do {
        bool ok = true;
        for(int i = 0; i < n - 1; i++) {
            if(a[i] % (i + 1) != 0) {
                ok = false;
            }
        }
        if(ok && a[n-1] == 1 && a[0] == x) {
            for(auto &x : a) {
                cerr << x << " ";
            }
            cerr << nl;
        }
    } while(next_permutation(all(a)));
}
void solve(){

    int n,x;
    cin>>n>>x;
    //test(n,x);

    if(n % x != 0) {
        cout << -1 << nl;
        return;
    }

    vector<int> ans(n);
    ans[0] = x;
    ans[n-1] = 1;
    for(int i = 2; i <= n - 1; i++) {
        if(i == x && x != n) {
            ans[i-1] = n;
        } else {
            ans[i-1] = i;
        }
    }

    for(int i = x+1; i < n; i++) {
        if(ans[x-1] % i == 0 && ans[i-1] % x == 0) {
            swap(ans[x-1], ans[i-1]);
            x = i;
        }
    }
    for(auto &x : ans) {
        cout << x << " ";
    }
    cout << nl;
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

