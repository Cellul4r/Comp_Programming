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
    vector<bool> a(n+1);
    for(int i = 1; i <= n; i++) {
        int x; cin>>x;
        a[x] = 1;
    }

    vector<int> ans(n+1, INF);
    for(int i = 1; i <= n; i++) {
        if(a[i]) ans[i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        if(ans[i] == INF) continue;
        for(int j = i; j <= n; j += i) {
            ans[j] = min(ans[j], ans[i] + ans[j / i]);
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << (ans[i] == INF ? -1 : ans[i]) << " ";
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

