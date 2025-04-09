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
    
    int n,m;
    cin>>n>>m;
    vector<vector<int>> board(n,vector<int>(m));
    vector<int> sumL(m), sumU(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin>>s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'L') {
                board[i][j] = 1;
                sumL[j]++;
            } else if(s[j] == 'U') {
                board[i][j] = 2;
                sumU[i]++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(sumU[i] & 1) {
            cout << -1 << nl;
            return;
        }
    }
    for(int i = 0; i < m; i++) {
        if(sumL[i] & 1) {
            cout << -1 << nl;
            return;
        }
    }
    
    vector<vector<int>> color(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 1) {
                if(sumL[j] & 1) {
                    color[i][j] = 1;
                    color[i][j+1] = 2;
                } else {
                    color[i][j] = 2;
                    color[i][j+1] = 1;
                }
                sumL[j]--;
            } else if(board[i][j] == 2) {
                if(sumU[i] & 1) {
                    color[i][j] = 1;
                    color[i+1][j] = 2;
                } else {
                    color[i][j] = 2;
                    color[i+1][j] = 1;
                }
                sumU[i]--;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(color[i][j] == 0) {
                cout << '.';
            } else if(color[i][j] == 1) {
                cout << 'W';
            } else {
                cout << 'B';
            }
        }
        cout << nl;
    }
    cout << nl;
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

