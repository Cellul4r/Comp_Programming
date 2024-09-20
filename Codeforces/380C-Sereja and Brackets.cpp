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
using pii = pair<int,int>;
using piL = pair<int,long>;
using pip = pair<int,pair<int,int>>;
const int INF = 1e9;
const int N = 1e6+5;

struct bracket {

    ll l = 0, r = 0, maxL = 0;
};
struct segtree {

    typedef bracket T;
    vector<T> t;
    T id;
    T f(T a, T b) {
        T c;
        ll minBracket = min(a.l,b.r);
        a.l -= minBracket;
        a.r -= minBracket;
        c.l = a.l + b.l;
        c.r = a.r + b.r;
        c.maxL = a.maxL + b.maxL + 2 * minBracket;
        return c;
    }
    void build(ll node,ll l,ll r, string& S) {
        if(l == r) {
            if(S[l] == '(') {
                t[node].l += 1;
            } else {
                t[node].r += 1;
            }
            return;
        }

        ll mid = (l + r) / 2;
        build(2*node,l,mid,S);
        build(2*node+1,mid+1,r,S);
        t[node] = f(t[node*2],t[node*2+1]);
    }

    T query(ll node, ll l, ll r, ll qL, ll qR) {
        if(r < qL || l > qR) {
            return id;
        }
        if(l >= qL && r <= qR) return t[node];
        ll mid = (l + r) / 2;
        return f(query(2*node,l,mid,qL,qR),query(2*node+1,mid+1,r,qL,qR));
    }
};
void solve() {
    
    string s;
    cin>>s;
    int m;
    cin>>m;
    ll n = s.length();
    segtree seg;
    seg.t.resize(4*n);
    seg.build(1,0,n-1,s);
    for(int i=0;i<m;++i) {
        ll l,r;
        cin>>l>>r;
        --l;
        --r;
        auto ans = seg.query(1,0,n-1,l,r);
        cout << ans.maxL << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;

    while(t--) {
        solve();
    }
    return 0;
}

