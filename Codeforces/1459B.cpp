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
const int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};

set<pi> points;
set<array<int,4>> vis;
void recur(int i, int j, int k, int now, int& n) {
    if(now == n) {
        points.insert(make_pair(i,j));
        return;
    }
    //cerr << i << " " << j << " " << k << nl;
    /*if(vis.count({i,j,k,now})) {
        return;
    }*/
    vis.insert({i,j,k,now});
    int ni = i + dr[k], nj = j + dc[k];
    if(k == 0 || k == 2) {
        // have to west or east    
        recur(ni,nj,1,now+1,n);
        recur(ni,nj,3,now+1,n);
    } else {
        recur(ni,nj,0,now+1,n);
        recur(ni,nj,2,now+1,n);
    }
}
void solve(){
    
    int n;
    cin>>n;
    if(n % 2 == 0) {
        cout << (n / 2 + 1) * (n / 2 + 1);
    } else {
        int x = n / 2;
        cout << 2 * x * x + 6 * x + 4;
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

