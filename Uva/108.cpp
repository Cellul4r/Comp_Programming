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
const int N =1e2+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n;
int a[N][N];

int kadane(vector<int>& cur) {

    int maxSum = cur[0], now = cur[0];
    for(int i = 1; i < n; i++) {
        now = max(cur[i], cur[i] + now);
        maxSum = max(maxSum, now);
    }
    return maxSum;
}
void solve(){
    
    cin>>n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin>>a[i][j];
        }
    }

    int ans = a[0][0];
    for(int l = 0; l < n; l++) {

        vector<int> cur(n);
        for(int r = l; r < n; r++) {
            
            for(int i = 0; i < n; i++) {
                cur[i] += a[i][r];
            }

            ans = max(ans,kadane(cur));
        }
    }
    cout << ans << nl;
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

