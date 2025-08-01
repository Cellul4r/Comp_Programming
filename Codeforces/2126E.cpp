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
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = 0; i < n; i++) {
        cin>>b[i];
    }
    int val = a[n-1];
    bool flag = true;
    
    if(val != b[0]) {
        flag = false;
    }

    for(int i = 1; i < n; i++) {
        if(a[i-1] % a[i] != 0) flag = false;
    }
    for(int i = 0; i < n - 1; i++) {
        if(b[i+1] % b[i] != 0) flag = false;
    }
    for(int i = 1; i < n - 1; i++) {
        if(__gcd(a[i],b[i]) != val) flag =false;
    }
    for(int i = 0; i < n - 1; i++) {
        if(__gcd(a[i],b[i+1]) != val) flag = false;
    }
    cout << (flag ? "YES" : "NO") << nl;
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

