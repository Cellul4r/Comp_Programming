/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N = 4;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
int dx[4],dy[4];
bool vis[N][N];
ll recur(int y, int x) {
    if(y == 4 && x == 4) return 1;
    if(x == 4) return recur(y+1, 0);
    if(vis[y][x]) return recur(y, x+1);
    //cerr << y << " " << x << nl;
    vis[y][x] = true;
    ll ans = 0;
    for(int i = 0; i < 4; i++) {
        int ny = dy[i] + y, nx = dx[i] + x;
        if(ny < 0 || nx < 0 || ny >= 4 || nx >= 4 || vis[ny][nx]) continue;
        vis[ny][nx] = true;
        ans += recur(y,x+1); 
        vis[ny][nx] = false;
    }
    vis[y][x] = false;
    ans += recur(y, x+1);
    return ans;
}
void solve(){
    
    // (0,0):(2,2)
    // (0,1):(1,0)
    // (0,2):(1,3)
    // (0,3):(1,1)
    while(true) {
        for(int i = 0; i < 4; i++) {
            cin>>dx[i]>>dy[i];
            if(dx[0] > 4) return;
        }
        cout << recur(0,0) << nl;
    }
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

