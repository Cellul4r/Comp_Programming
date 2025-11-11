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
int ask(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int x;
    cin>>x;
    return x;
}

void solve(){
    
    int n; cin>>n;
    queue<int> Q;

    vector<int> par(n+1);
    // root at 1
    for(int u = 2; u <= n; u++) {
        int v = 1;
        while(true) {
            int x = ask(v,u);
            if(x == v) break;
            v = x;
        }
        par[u] = v;
    }
    cout << "! ";
    for(int i = 2; i <= n; i++) cout << par[i] << " " << i << " ";
    cout << endl;
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

