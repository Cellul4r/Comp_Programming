/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        a[x] = i;
    }

    // mx number is odd parity index or not
    if(a[n] % 2 == 1) {
        // we can do sorted array, or reverse sorted array or not
        bool odd = true;
        bool ok = true;
        for(int i = n - 1; i >= 1; i--) {
            bool o = (a[i] % 2 == 1);
            if(odd == o) {
                ok = false;
                break;
            }
            odd = o;
        }
        if(ok) {
            cout << "YES\n";
            return;
        }
    }
    if(a[n] % 2 == 0 && n % 2 == 0) {
        // edge case we can let start at the hill at index k = n (which is even parity)
        bool odd = false;
        bool ok = true;
        for(int i = n - 1; i >= 1; i--) {
            bool o = (a[i] % 2 == 1);
            if(odd == o) {
                ok = false;
                break;
            }
            odd = o;
        }
        if(ok) {
            cout << "YES\n";
            return;
        }

    }
    bool ok = true;
    bool odd = (a[n] % 2 == 1);
    bool l = !odd, r = !odd;
    for(int i = n - 1; i >= 1; i --) {
        bool o = (a[i] % 2 == 1);
        if(l == o) {
            l = !l;
        } else if(r == o) {
            r = !r;
        } else {
            ok = false;
            break;
        }
    }
    cout << (ok ? "YES\n" : "NO\n");
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

