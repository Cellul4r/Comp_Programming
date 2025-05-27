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
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

struct segtree {

    int n;
    ll t1[4*N],t2[4*N];
    
    void init(int n) {
        return;
    }

    ll f(ll a, ll b) {
        return a + b; 
    }

    void update1(int node, int l, int r, int idx, int v) {
        if(l == r) {
            t1[node] += v;
            return;
        }
        int mid = (l + r) >> 1;
        if(idx <= mid) {
            update1(node<<1,l,mid,idx,v);
        } else {
            update1(node<<1|1,mid+1,r,idx,v);
        }
        t1[node] = f(t1[node<<1],t1[node<<1|1]);
    }

    void update2(int node, int l, int r, int idx, int v) {
        if(l == r) {
            t2[node] += v;
            return;
        }
        int mid = (l + r) >> 1;
        if(idx <= mid) {
            update2(node<<1,l,mid,idx,v);
        } else {
            update2(node<<1|1,mid+1,r,idx,v);
        }
        t2[node] = f(t2[node<<1],t2[node<<1|1]);
    }

    ll query1(int node, int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(l >= L && r <= R) return t1[node];
        
        int mid = (l + r) >> 1;
        return f(query1(node<<1,l,mid,L,R), query1(node<<1|1,mid+1,r,L,R));
    }

    ll query2(int node, int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(l >= L && r <= R) return t2[node];

        int mid = (l + r) >> 1;
        return f(query2(node<<1,l,mid,L,R), query2(node<<1|1,mid+1,r,L,R));
    }
};
void solve(){
    
    int n,q;
    cin>>n>>q;

    segtree seg;
    //seg.init(n);
    vector<ll> row(n), col(n);
    for(int i = 0; i < q; i++) {
        int t;
        cin>>t;
        if(t == 1) {
            int x,y;
            cin>>x>>y;
            x--,y--;
            row[x]++;
            col[y]++;
            if(row[x] == 1) seg.update1(1,0,n-1,x,1);
            if(col[y] == 1) seg.update2(1,0,n-1,y,1);
        } else if(t == 2) {
            int x,y;
            cin>>x>>y;
            x--,y--;
            row[x]--;
            col[y]--;
            if(row[x] == 0) seg.update1(1,0,n-1,x,-1);
            if(col[y] == 0) seg.update2(1,0,n-1,y,-1);
        } else {
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            a--,b--,c--,d--;
            ll x = seg.query1(1,0,n-1,a,c);
            ll y = seg.query2(1,0,n-1,b,d);
            //cerr << x << " CHECK " << y << nl;
            if(x == c - a + 1 || y == d - b + 1) {
                cout << "YES" << nl;
            } else {
                cout << "NO" << nl;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    /*
    string s = "";
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
    */

    //cin>>t;
    while(t--)solve();

    return 0;
}

