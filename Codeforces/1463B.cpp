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
    vector<int> a(n), b(n);
    ll s = 0;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        s += a[i];
    }

    ll sum = 0;
    for(int i = 0; i < n; i += 2) {
        b[i] = a[i];
        sum += abs(b[i] - a[i]);
    }
    for(int i = 1; i < n; i += 2) {
        b[i] = 1;
        sum += abs(1 - a[i]);
    }
    if(2 * sum > s) {
        sum = 0;
        for(int i = 1; i < n; i += 2) {
            b[i] = a[i];
            sum += abs(b[i] - a[i]);
        }
        for(int i = 0; i < n; i += 2) {
            b[i] = 1;
            sum += abs(1 - a[i]);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
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

