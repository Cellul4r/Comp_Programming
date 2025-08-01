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
const int N = 19;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

int dp[N][N][N];
void solve(){
    
    int n,c,m;
    cin>>n>>c>>m;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            cin>> a[i][j];
            a[j][i] = a[i][j];
        }
    }

    /*for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                if(i == j) dp[i][j][1] = 0;
                for(int l = 0; l < c; l++) {
                    if(i == j && l == 1)  continue;

                }
            }
        }
    }*/
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cerr << a[i][j] << " ";
        }
        cerr << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin>>t;
    while(t--)solve();

    return 0;
}

