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
const int N =1e3+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

const int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
const char direct[] = {'v', '<', '^', '>'};
int h,w;
int board[N][N];
char level[N][N];
void solve(){
    
    cin>>h>>w;
    queue<pi> Q;
    for(int i = 1; i <= h; i++) {
        string s;
        cin>>s;
        for(int j = 1; j <= w; j++) {
            level[i][j] = -1;
            if(s[j-1] == '.') {
                level[i][j] = '.';
                board[i][j] = 1;
            } else if(s[j-1] == 'E') {
                cerr << i << j << nl;
                Q.push(make_pair(i,j));
                level[i][j] = 'E';
                board[i][j] = 2;
            } else {
                level[i][j] = '#';
            }
        }
    }
    // bfs?
    while(!Q.empty()) {
        int ur = Q.front().first, uc = Q.front().second;
        //cerr << ur << " " << uc << nl;
        Q.pop();
        for(int i = 0; i < 4; i++) {
            int vr = ur + dr[i], vc = uc + dc[i];
            if(vr <= 0 || vr > h || vc <= 0 || vc > w || board[vr][vc] == 0) {
                continue;
            }
            if(board[vr][vc] == 2 || (board[vr][vc] == 1 && level[vr][vc] != '.')) continue;
            level[vr][vc] = direct[i];
            //cerr << vr << vc << nl;
            Q.push(make_pair(vr,vc));
        }
    }

    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            cout << level[i][j];
        }
        cout << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    //cin>>t;
    while(t--)solve();

    return 0;
}

