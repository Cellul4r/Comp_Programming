#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define L long
#define sLL signed long long
#define uLL unsigned long long
#define f first 
#define s second
#define pf printf
#define sf scanf
#define A(a) (a).begin(),(a).end()
using pii = pair<int,int>;
using piL = pair<int,long>;
using pip = pair<int,pair<int,int>>;
const int INF = 1e9;
const int N = 1e6+10;
 
struct segtree {
 
    vector<vector<ll>> t;
    ll id = 0;
    void init(int n) {
        t.resize(4*n,vector<ll>(4*n,0));
    }
 
    ll comb(ll a, ll b) {
        return a+b;
    }
    void build_y(ll nodex,ll nodey, ll lx, ll rx, ll ly, ll ry, vector<vector<int>>& a) {
        if(ly == ry) {
            if(lx == rx) {
                t[nodex][nodey] = a[lx][ly];
            } else {
                t[nodex][nodey] = comb(t[nodex<<1][nodey], t[nodex<<1|1][nodey]);
            }
            return;
        }
        ll mid = (ly+ry) >> 1;
        build_y(nodex,nodey<<1,lx,rx,ly,mid,a);
        build_y(nodex,nodey<<1|1,lx,rx,mid+1,ry,a);
        t[nodex][nodey] = comb(t[nodex][nodey<<1], t[nodex][nodey<<1|1]);
    }
 
    void build_x(ll nodex, ll lx, ll rx, vector<vector<int>>& a, int n) {
        if(lx != rx) {
            ll mid = (lx + rx) >> 1;
            build_x(nodex<<1,lx,mid,a,n);
            build_x(nodex<<1|1,mid+1,rx,a,n);
        }
        build_y(nodex, 1, lx, rx, 0, n-1, a);
    }
 
    ll queryY(ll nodex, ll nodey, ll ly, ll ry , ll qL, ll qR) {
        
        if(ly > ry || ly > qR || ry < qL) return 0;
        if(ly >= qL && ry <= qR) {
            return t[nodex][nodey];
        }
 
        ll mid = (ly + ry) >> 1;
        return comb(queryY(nodex,nodey<<1,ly,mid,qL,qR),queryY(nodex,nodey<<1|1,mid+1,ry,qL,qR));
    }
 
    ll queryX(ll nodex, ll lx, ll rx, ll qLx, ll qRx, ll qLy, ll qRy, int n) {
        if(lx > rx || lx > qRx || rx < qLx) return 0;
        if(lx >= qLx && rx <= qRx) {
            return queryY(nodex,1, 0, n-1, qLy, qRy);
        }
        ll mid = (lx + rx) >> 1;
        return comb(queryX(nodex<<1,lx,mid,qLx,qRx,qLy,qRy,n),queryX(nodex<<1|1,mid+1,rx,qLx,qRx,qLy,qRy,n));
    }
};
void solve() {
    
    int n,q;
    cin>>n>>q;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i=0;i<n;++i) {
        string k;
        cin>>k;
        for(int j=0;j<n;++j) {
            if(k[j] == '*') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    /*for(int i=0;i<n;++i) {
        for(int j=0;j<n;++j) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    } */
    segtree seg;
    seg.init(n);
    seg.build_x(1, 0, n-1, a, n);
    while(q--) {
        ll x1,y1,x2,y2;
        cin>>y1>>x1>>y2>>x2;
        --y1;--x1;--y2;--x2;
        cout << seg.queryX(1,0,n-1,y1,y2,x1,x2,n) << endl;
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin>>t;
 
    while(t--) {
        solve();
    }
    return 0;
}
