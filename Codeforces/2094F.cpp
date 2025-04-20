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

int n,m;
void show(vector<vector<int>>& board) {
    for(int i = 0; i < (int)board.size(); i++) {
        for(int j = 0; j < (int)board[i].size(); j++) {
            cout << board[i][j] << " ";
        }
        cout << nl;
    }
    cout << nl;
}
void solve(){
    
    int k;
    int times;
    cin>>n>>m>>k;
    times = n * m / k;
    vector<vector<int>> board(n,vector<int>(m));
    if(n == 1) {
        int now = 1;
        int x = 0;
        for(int j = 0; j < m; j += 2) {
            board[0][j] = now;
            x++;
            if(x == times) {
                now++;
                x = 0;
            }
        }
        for(int j = 1; j < m; j += 2) {
            board[0][j] = now;
            x++;
            if(x == times) {
                now++;
                x = 0;
            }
        }
        show(board);
        return;
    }
    if(m == 1) {
        int now = 1;
        int x = 0;
        for(int j = 0; j < n; j += 2) {
            board[j][0] = now;
            x++;
            if(x == times) {
                now++;
                x = 0;
            }
        }
        for(int j = 1; j < n; j += 2) {
            board[j][0] = now;
            x++;
            if(x == times) {
                now++;
                x = 0;
            }
        }
        show(board);
        return;
    }
    if(n == 2) {
        int now = 1;
        int x = 0;
        int up = 0,l=0;
        for(int j = 0; j < m; j++) {
            board[l][j] = now;
            x++;
            if(x == times) {
                now++;
                x = 0;
            }
            if(up) {
                l--;
            } else {
                l++;
            }
            up ^= 1;
        }
        up = 1, l = 1;
        for(int j = 0; j < m; j++) {
            board[l][j] = now;
            x++;
            if(x == times) {
                now++;
                x = 0;
            }
            if(up) {
                l--;
            } else {
                l++;
            }
            up ^= 1;
        }

        show(board);
        return;
    }
    if(m == 2) {
        int now = 1;
        int x = 0;
        int up = 1,l=0;
        for(int j = 0; j < n; j++) {
            board[j][l] = now;
            x++;
            if(x == times) {
                now++;
                x = 0;
            }
            if(up) {
                l++;
            } else {
                l--;
            }
            up ^= 1;
        }
        up = 0;
        l = 1;
        for(int j = 0; j < n; j++) {
            board[j][l] = now;
            x++;
            if(x == times) {
                now++;
                x = 0;
            }
            if(up) {
                l++;
            } else {
                l--;
            }
            up ^= 1;
        }
        show(board);
        return;
    }
    int tmpN = n, tmpM = m;
    if(n > m) {
        vector<vector<int>> tmp(m,vector<int>(n));
        board = tmp;
        swap(n,m);
    }
    vector<pair<int,int>> cnt[n+1];
    for(int i = 0, now = 1; i < n && now < n; i++, now++) {
        int up = (n & 1 ? 0 : i % 2), l = i; 
        for(int j = 0; j < m; j++) {
            board[l][j] = now;
            cnt[now].push_back(make_pair(l,j));
            if(up) {
                l--;
            } else {
                l++;
            }
            up ^= 1;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!board[i][j]) {
                board[i][j] = n;
                cnt[n].push_back(make_pair(i,j));
            }
        }
    }
    //show(board);
    int now = 1;
    int x = 0;
    for(int i = 1; i < n; i += 2) {
        for(auto &y : cnt[i]) {
            int r = y.first, c = y.second;
            //cerr << r << " " << c << nl;
            board[r][c] = now;
            x++;
            if(x == times) {
                now++;
                x = 0;
            }
        }
    }
    for(int i = 2; i < n; i += 2) {
        for(auto &y : cnt[i]) {
            int r = y.first, c = y.second;
            //cerr << r << " " << c << nl;
            board[r][c] = now;
            x++;
            if(x == times) {
                now++;
                x = 0;
            }
        }
    }

    for(auto &y : cnt[n]) {
        int r = y.first, c = y.second;
        //cerr << r << " " << c << nl;
        board[r][c] = now;
        x++;
        if(x == times) {
            now++;
            x = 0;
        }
    }
    if(tmpN != n || tmpM != m) {
        vector<vector<int>> tmp(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                tmp[i][j] = board[j][i];
            }
        }
        board = tmp;
    }
    show(board);
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

