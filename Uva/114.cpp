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

const int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
void setIO(string);
int n,m,p;
int a[N][N];
int bumper[N][N];
int cost[N][N];
ll life,wall,score;
int k;
void solve(){

    memset(a, 0, sizeof a);
    memset(bumper, 0, sizeof bumper);
    memset(cost, 0, sizeof cost);
    cin>>m>>n>>wall>>p;
    for(int i = 0; i < p; i++) {
        int x,y;
        cin>>x>>y;
        a[x][y] = 1;
        cin>>bumper[x][y]>>cost[x][y];
    }

    int x,y;
    ll ans = 0;
    while(cin>>x>>y) {
        cin>>k>>life;
        score = 0;
        while(life > 1) {
            //cout << x << " " << y << " " << life << " " << k << nl;
            life--;
            int nx = x + dx[k], ny = y + dy[k];
            if(nx == 1 || ny == 1 || nx == m || ny == n) {
                // wall
                k = (k - 1 + 4) % 4;
                life -= wall;
            } else if(a[nx][ny]) {
                // bumpber
                k = (k - 1 + 4) % 4;
                score += bumper[nx][ny];
                life -= cost[nx][ny];
            } else {
                x = nx;
                y = ny;
            }
        }
        ans += score;
        cout << score << nl;
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

