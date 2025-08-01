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

void solve(){
    
    int n,q;
    cin>>n>>q;
    vector<int> pre[3];
    for(int i = 0; i < 3; i++) pre[i].resize(n+1,0);
    for(int i = 1; i <= n; i++) {
        int x;
        cin>>x;
        x--;
        pre[x][i] = 1;
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 3; j++) {
            pre[j][i] += pre[j][i-1];
        }
    }

    for(int i = 0; i < q; i++) {
        int l,r;
        cin>>l>>r;
        for(int j = 0; j < 3; j++) {
            cout << pre[j][r] - pre[j][l-1] << (j != 2 ? " " : "");
        }
        cout << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    string s = "bcount";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

