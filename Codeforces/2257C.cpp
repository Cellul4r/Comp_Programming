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
    
    // we need to find minimum k cameras? how??
    // sort the ai? since pi < i
    int n; cin>>n;
    vector<int> p(n+1, 0);
    for(int i = 2; i <= n; i++) {
        int x; cin>>x;
        p[i] = x;
    }

    int m; cin>>m;
    vector<int> a(m);
    for(auto &x : a) {
        cin>>x;
    }
    sort(all(a));
    reverse(all(a));
    cout << m - 1 << " ";
    for(int i = 0; i < m-1; i++) {
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

