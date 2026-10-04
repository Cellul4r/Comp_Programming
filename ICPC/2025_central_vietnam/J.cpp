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
const int dr[] = {-1,0,1,0};
const int dc[] = {0,1,0,-1};
int n,m;
int a[N][N];
int level[N][N][4];
int sr,sc,ddr,ddc;
void solve(){

    memset(level, -1, sizeof level);
    cin>>n>>m;
    for(int i = 0; i < n; i++) {
        string s;
        cin>>s;
        for(int j = 0; j < m; j++) {
            if(s[j] == 'S') {
                sr = i;
                sc = j;
            } else if(s[j] == 'D') {
                ddr = i;
                ddc = j;
            } else if(s[j] == '+') {
                a[i][j] = 1;
            }
        }
    }

    for(int k = 1; k <= 3; k++) level[sr][sc][k] = 0;
    queue<array<int,3>> Q;
    Q.push({sr,sc,3});
    while(!Q.empty()) {
        int ur = Q.front()[0], uc = Q.front()[1], hp = Q.front()[2];
        Q.pop();

        for(int k = 0; k < 4; k++) {
            int vr = ur + dr[k], vc = uc + dc[k];
            if(vr < 0 || vc < 0 || vr >= n || vc >= m || (hp == 1 && a[vr][vc] == 1) || level[vr][vc][hp - a[vr][vc]] != -1) continue;
            level[vr][vc][hp - a[vr][vc]] = level[ur][uc][hp] + 1;
            Q.push({vr,vc,hp-a[vr][vc]});
        }
    }

    int ans = INF;
    for(int k = 1; k <= 3; k++) {
        if(level[ddr][ddc][k] == -1) continue;
        ans = min(ans, level[ddr][ddc][k]);
    }
    cout << (ans == INF ? -1 : ans);
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

