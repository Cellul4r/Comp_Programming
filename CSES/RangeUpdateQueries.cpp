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
const int N = 2e5+10;

struct segtree {

    vector<ll> t;
    vector<ll> lazy;
    ll id = 0;
    void init(int n) {
        t.resize(4*n+5,id);
        lazy.resize(4*n+5,id);
    }

    ll f(ll a, ll b) {
        return a + b;
    }
    void build(ll node, ll l, ll r, vector<int>& a) {
        if(l == r) {
            t[node] = a[l];
            return;
        }
        ll mid = (l + r) >> 1;
        build(node<<1,l,mid,a);
        build(node<<1|1,mid+1,r,a);
        t[node] = f(t[node<<1],t[node<<1|1]);
    }

    void apply(ll node, ll l, ll r, ll v) {
        if(lazy[node]) {
            t[node] += (r-l+1)*v;
            if(l != r) {
                lazy[node<<1] += v;
                lazy[node<<1|1] += v;
            }
            lazy[node] = 0;
        }
    }
    void rangeUpdate(ll node, ll l, ll r, ll qL, ll qR, ll v) {
        // check this node does it have lazy propagation?
        apply(node,l,r,lazy[node]);
        if(l > r || l > qR || r < qL) return;

        if(l >= qL && r <= qR) {
            t[node] += (r-l+1) * v;
            //not leaf node
            if(l != r) {
                lazy[node<<1] += v;
                lazy[node<<1|1] += v;
            }
            return;
        }
        ll mid = (l+r) >> 1;
        rangeUpdate(node<<1,l,mid,qL,qR,v);
        rangeUpdate(node<<1|1,mid+1,r,qL,qR,v);

        t[node] = f(t[node<<1],t[node<<1|1]);
    }

    ll query(ll node, ll l, ll r, ll pos) {
        apply(node,l,r,lazy[node]);
        if(l == r) return t[node];
        ll mid = (l+r)>>1;
        if(pos <= mid) return query(node<<1,l,mid,pos);
        else return query(node<<1|1,mid+1,r,pos); 
    }
};
void solve() {
    
    int n,q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;++i) {
        cin>>a[i];
    }
    segtree seg;
    seg.init(n);
    seg.build(1,0,n-1,a);
    while(q--) {
        int op;
        cin>>op;
        if(op == 1) {
            ll l,r,k;
            cin>>l>>r>>k;
            --l,--r;
            seg.rangeUpdate(1,0,n-1,l,r,k);
        } else {
            ll k;
            cin>>k;
            --k;
            cout << seg.query(1,0,n-1,k) << endl;
        }
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

