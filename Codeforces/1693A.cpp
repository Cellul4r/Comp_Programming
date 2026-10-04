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
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    // first op : bi
    // second op : ci
    // ai = bi - ci
    // ci = bi-1 
    // ai = bi - bi-1
    // bi = ai + bi-1
    // c0 = 0
    // b0 = a0 
    // bn-1 = an-1
    // !!! bi >= 0
    // bi = 0 then we never go to next element i+1 
    // bj = 0 for each j >= i and bi = 0
    vector<ll> b(n, 0); 
    b[0] = a[0];
    for(int i = 1; i < n; i++) {
        b[i] = a[i] + b[i-1]; 
    }

    if(b[n-1] != 0) {
        cout << "NO" << nl;
        return;
    }
    int idx = -1;
    for(int i = 0; i < n; i++) {
        if(b[i] < 0) {
            cout << "NO" << nl;
            return;
        }
        if(idx != -1 && b[i] != 0) {
            cout << "NO" << nl;
            return;
        }
        if(b[i] == 0 && idx == -1) {
            idx = i;
        }
    }
    cout << "YES" << nl;
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

