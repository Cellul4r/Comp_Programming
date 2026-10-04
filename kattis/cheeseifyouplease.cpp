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
const int N =55;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n,m;
double a[N], b[N], c[N][N];
double recur(int i, vector<double> cur) {

}
void solve(){
    
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin>>c[j][i];
        }
        cin>>b[i];
    }

    double ans = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    //cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

