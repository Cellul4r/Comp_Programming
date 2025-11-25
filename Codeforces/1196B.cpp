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
    
    int n,k; cin>>n>>k;
    vector<int> a(n+1);
    int odd = 0;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        if(a[i] & 1) {
            odd++;
        }
    }

    if(k > odd || (odd - k) % 2 == 1) {
        cout << "NO" << nl;
        return;
    }
    // 1, 1, 1, 1, ..., ..., odd - k + 1
    cout << "YES" << nl;
    for(int i = 1; i <= n && k > 1; i++) {
        if(a[i] & 1) {
            cout << i << " ";
            k--;
        }
    }
    cout << n << nl;
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

