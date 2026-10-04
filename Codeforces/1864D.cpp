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
    
    int n; cin>>n;
    // column fills
    vector<bool> col(n+1,0);
    // right diagonal
    vector<vector<bool>> pre1(2*n+1, vector<bool>(n+1,0));
    // left diagonal
    vector<vector<bool>> pre2(2*n+1, vector<bool>(n+1,0));
    vector<vector<bool>> a(n+1, vector<bool>(n+1));
    for(int i = 1; i <= n; i++) {
        string s; cin>>s;
        for(int j = 1; j <= n; j++) {
            a[i][j] = s[j-1] - '0';
        }
    }
    
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        // go for each row from top to bottom
        for(int j = 1; j <= n; j++) {
            // go for each col from left to right or we can do right to left is ok
            a[i][j] = a[i][j] ^ col[j] ^ pre1[i-j+n][(i-j<n ? i-1:j-1)] ^ pre2[i+j][i-1];
            /*
            if(i == 2 && j == 2) {
                cout << i << " - " << j << " " << col[j] << " " << pre1[i-j+n][(i-j<n ? i-1:j-1)] << " " << pre2[i+j][i-1] << " : " << nl;
            }
            */
            if(a[i][j]) {
                //cout << i << " " << j << nl;
                ans++;
            }
            col[j] = col[j] ^ a[i][j] ^ pre1[i-j+n][(i-j<n ? i-1:j-1)] ^ pre2[i+j][i-1];
            pre1[i-j+n][(i-j<n ? i:j)] = pre1[i-j+n][(i-j<n ? i-1:j-1)] ^ a[i][j];
            pre2[i+j][i] = pre2[i+j][i-1] ^ a[i][j];
        }
        /*
        for(int j = 1; j <= n; j++) {
            cout << col[j] << " " << pre1[i-j+n][(i-j<n ? i:j)] << " " << pre2[i+j][i] << " : ";
        }
        cout << nl;
        */
    }
    cout << ans << nl;
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

