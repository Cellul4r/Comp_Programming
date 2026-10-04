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
const int N = 500;
const int M = 202;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int n,m;
int a[N][N];
int w[N][N], b[N][N];
bool vis[N][N];
int findSum(bool wh, int r1, int c1, int r2, int c2) {
    int sum;
    if(wh) {
        sum = w[r2][c2] - w[r2][c1-1] - w[r1-1][c2] + w[r1-1][c1-1];
    } else {
        sum = b[r2][c2] - b[r2][c1-1] - b[r1-1][c2] + b[r1-1][c1-1];
    }
    return sum;
}
void solve(){
    
    memset(a, 0, sizeof a);
    for(int i = 1; i <= n; i++) {
        string s;
        cin>>s;
        for(int j = 1; j <= m; j++) {
            if(s[j-1] == '#') {
                a[i+M][j+M] = 1;
                if(i == 1) {
                    for(int k = 1; k < i + M; k++) {
                        a[k][j+M] = 1;
                    }
                }
                if(i == n) {
                    for(int k = n + M + 1; k < N; k++) {
                        a[k][j+M] = 1;
                    }
                }
            }
        }

        if(a[i+M][1+M] == 1) {
            for(int j = 1; j < 1 + M; j++) {
                a[i+M][j] = 1;
            }
        }

        if(a[i+M][m+M] == 1) {
            for(int j = m + M + 1; j < N; j++) {
                a[i+M][j] = 1;
            }
        }
    }

    for(int i = 1; i < N; i++) {
        for(int j = 1; j < N; j++) {
            if(a[i][j] == 1) {
                b[i][j] = 1 + b[i-1][j] + b[i][j-1] - b[i-1][j-1];
            } else {
                w[i][j] = 1 + w[i-1][j] + w[i][j-1] - w[i-1][j-1];
            }
        }
    }

    set<int> can;
    for(int w = 1; w <= 2; w++) {
        memset(vis, false, sizeof vis);
        bool ok = true;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(vis[i+M][j+M]) continue;
                bool wh = false;
                if(a[i+M][j+M] == 0) wh = true;
                if(i == 1 && j == 2) {
                    //cout << "SUM:" << findSum(wh, i + M - w + 1, j + M, i + M, j + M + w - 1) << nl;
                    //cout << i + M - w + 1 << " " << j + M << " " << i << " " << j + M + w - 1 << nl;
                }
                if(findSum(wh, i + M, j + M, i + M + w - 1, j + M + w - 1) == w * w) {
                    for(int k = 1; k <= w; k++) {
                        for(int l = 1; l <= w; l++) {
                            vis[i+M+k-1][l+M+k-1] = true;
                        }
                    }
                } else if(findSum(wh, i + M - w + 1, j + M - w + 1, i + M, j + M) == w * w) {
                    for(int k = 1; k <= w; k++) {
                        for(int l = 1; l <= w; l++) {
                            vis[i+M-w+1+k-1][j+M-w+1+k-1] = true;
                        }
                    }
                } else if(findSum(wh, i + M - w + 1, j + M, i + M, j + M + w - 1) == w * w) {
                    for(int k = 1; k <= w; k++) {
                        for(int l = 1; l <= w; l++) {
                            vis[i+M-w+1+k-1][j+M+k-1] = true;
                        }
                    }
                    
                } else {
                    //cout << wh << nl;
                    cout << w << " " << i << " " << j << nl;
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            cout << w << nl;
            can.insert(w);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    do {
        cin>>n>>m;
        if(n == 0 && m == 0) break;
        solve();
    }while(true);

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

