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
    
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        a[i] %= 3;
    }

    for(int l = 1; l < n - 1; l++) {
        for(int r = l + 1; r < n; r++) {
            set<int> now;
            int s = 0;
            for(int i = 1; i <= l; i++) {
                s = (s + a[i]) % 3;
            }
            now.insert(s);
            s = 0;
            for(int i = l+1; i <= r; i++) {
                s = (s + a[i]) % 3;
            }
            now.insert(s);
            s = 0;
            for(int i = r+1; i <= n; i++) {
                s = (s + a[i]) % 3;
            }
            now.insert(s);
            if(now.size() == 3 || now.size() == 1) {
                cout << l << " " << r << nl;
                return;
            }
        }
    }
    cout << 0 << " " << 0 << nl;
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

