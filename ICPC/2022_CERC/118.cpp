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

void setIO(string);
const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};
int n,m,x,y;
string a;
int k;
bool vis[100][100];
void solve(){
    cin>>n>>m; 
    memset(vis, false, sizeof false);
    while(cin>>x>>y) {
        char c;
        cin>>c;
        if(c == 'N') k = 0;
        else if(c == 'E') k = 1;
        else if(c == 'S') k = 2;
        else k = 3;
        cin>>a;
        bool lost = false;
        for(auto &i : a) {
            if(i == 'L') {
                k = (k - 1 + 4) % 4;
            } else if(i == 'R') {
                k = (k + 1) % 4;
            } else {
                int nx = x + dx[k], ny = y + dy[k];
                if(nx < 0 || ny < 0 || nx > n || ny > m) {
                    if(!vis[x][y]) {
                        lost = true;
                        break;
                    }
                } else {
                    x = nx;
                    y = ny;
                }
            }
        }
        cout << x << " " << y << " ";
        if(k == 0) {
            cout << 'N';
        } else if(k == 1) cout << 'E';
        else if(k == 2) cout << 'S';
        else cout << 'W';
        if(lost) {
            cout << " LOST";
            vis[x][y] = true;
        }
        cout << nl;
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

