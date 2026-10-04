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
const int dx[] = {-1,0,1,0}, dy[] = {0,1,0,-1};
void solve(){
    
    string s; cin>>s;
    map<array<int,2>, bool> vis;
    int x = 0, y = 0;
    vis[{0,0}] = true;
    for(auto &k : s) {
        if(k == 'L') x--; 
        else if(k == 'R') x++;
        else if(k == 'U') y++;
        else y--;
        if(vis[{x,y}]) {
            cout << "BUG";
            return;
        }
        vis[{x,y}] = true;
    }
    for(auto &[x,y] : vis) {
        if(!y) continue;
        int cnt = -1;
        if(x[0] == 0 && x[1] == 0) cnt = 0;
        for(int k = 0; k < 4; k++) {
            if(vis[{x[0]+dx[k],x[1]+dy[k]}]) {
                cnt++;
            }
        }
        if(cnt > 1) {
            cerr << x[0] << " " << x[1] << " " << cnt;
            cout << "BUG";
            return;
        }
    }
    cout << "OK";
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

