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
    
    int n;
    cin>>n;
    vector<ll> b(n+1),a(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>b[i];
    }
    a[1] = 1;
    int cur = 1;
    for(int i = 2; i <= n; i++) {
        ll diff = b[i] - b[i-1];
        if(diff == i) {
            a[i] = ++cur;
        } else {
            a[i] = a[i-diff];
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << a[i] << " ";
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

