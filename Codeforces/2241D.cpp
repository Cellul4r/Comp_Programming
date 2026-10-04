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
    
    // if a[1] > b[1] -> NO
    //
    int n;  cin>>n;
    vector<ll> a(n+1), b(n+1);
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin>>b[i];
    }
    for(int i = n; i > 1; i--) {
        if(a[i] <= b[i]) {
            a[i] = b[i];
            continue;
        }
        a[i-1] += (a[i] - b[i]);
        a[i] = b[i];
    }
    if(a[1] <= b[1]) a[1] = b[1];
    for(int i = 1; i <= n; i++) {
        if(a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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

