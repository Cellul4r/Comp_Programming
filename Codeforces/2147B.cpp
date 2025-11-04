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
void test(int n) {
    vector<int> a(2*n);
    int run = 0;
    for(int i = 0; i < 2*n; i += 2) {
        a[i] = a[i+1] = ++run;
    }
    for(int i = 0; i < 2*n; i++) {
        cerr << a[i] << " ";
    }
    do {
        vector<int> l(n+1,-1), r(n+1);
        for(int i = 0; i < 2*n; i++) {
            if(l[a[i]] == -1) l[a[i]] = i;
            else r[a[i]] = i;
        }
        int ok = 1;
        for(int i = 1; i <= n; i++) {
            if((r[i] - l[i]) % i != 0) ok = 0;
        }
        if(ok) {
            for(auto &x : a) {
                cout << x << " ";
            }
            cout << nl;
        }
    } while(next_permutation(all(a)));
}
void solve(){
    
    int n; cin>>n;
    //test(n);
    vector<int> ans(2*n+1);    
    if(n == 1) {
        ans[1] = ans[2] = 1;
    } else if(n == 2) {
        cout << "1 2 1 2\n";
        return;
    } else if(n == 3) {
        cout << "1 3 1 2 3 2\n";
        return;
    }
    ans[1] = ans[n+1] = n;
    for(int i = 2, run = n-1; i <= n; i++) {
        ans[i] = run--;
    }
    for(int i = n+2, run = 1; i <= 2 * n; i++) {
        ans[i] = run++;
    }
    for(int i = 1; i <= 2*n; i++) {
        cout << ans[i] << " ";
    }
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

