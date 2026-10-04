/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
void solve(){
    
    int n; cin>>n;
    int l = -1e5, r = 1e5, u = 1e5, d = -1e5;
    // for robot that can't move left -> find max x among them.
    // for robot that can't move right -> find min x among them
    // for robot that can't move up -> find min y among them
    // for robot that can't move down -> find max y among them
    // plane 1D -> -1, 3, 5, 7, 9
    //              2  4  6  8  10
    for(int i = 1; i <= n; i++) {
        int x,y,ll,uu,rr,dd;
        cin>>x>>y>>ll>>uu>>rr>>dd;
        if(!ll) {
            l = max(l, x);
        }
        if(!rr) {
            r = min(r, x);
        }
        if(!uu) {
            u = min(u, y);
        }
        if(!dd) {
            d = max(d, y);
        }
    }
    if(l > r || u < d) {
        cout << 0 << nl;
        return;
    }
    // l is minimum x such that robot that can't move left can go
    // r is maximum x such that robot that can't move right can go
    // u is maximum y such that robot that can't move up can go
    cout << 1 << " " << l << " " << u << nl;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

