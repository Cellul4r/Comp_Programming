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
void test() {
    int n;
    cin>>n;
    for(int k = 0; k <= n * (n - 1) / 2; k++) {
        cout << k << nl;
        vector<int> a(n);
        iota(all(a), 1);
        do {
            int cnt = 0; 
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    bool inv = false;
                    for(int l = i; l <= j; l++) {
                        for(int r = l+1; r <= j; r++) {
                            if(a[l] > a[r]) {
                                inv = true;
                            }
                        }
                    }
                    if(inv) {
                        cnt++;
                    }
                }
            }
            if(cnt == k) {
                for(auto &x : a) cout << x << " ";
                cout << nl;
            }
        } while(next_permutation(all(a)));
    }
}
void solve(){

    test();
    // permutation of length n 
    // such that number of subsegments that not sorted = k
    ll n,k;
    cin>>n>>k;
    if(k == 0) {
        for(int i = 1; i <= n; i++) {
            cout << i << " ";
        }
        cout << nl;
        return;
    }
    if(k == n) {
        for(int i = n; i >= 1; i--) {
            cout << i << " ";
        }
        cout << nl;
        return;
    }
    vector<ll> save;
    for(ll i = 1; i <= n * (n-1) / 2ll; i++) {
        ll now = 1ll + 8 * (n * (n - 1) / 2ll - i); 
        ll check = sqrtl(now);
        if(check * check != now) continue;
        save.push_back(now);
    }
    ll lst = -1;
    for(auto &x : save) {
        if(x <= k) {
            lst = x;
        }
    }
    cerr << lst;
    cout << nl;
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

