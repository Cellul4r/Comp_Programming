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
struct p {
    int lft, rft, cntL, cntR, ans;
};
struct segtree {

    p t[4*N];
    int n;

    void init() {
    }

    p f(p a, p b) {
        if(a.ans == 0) return b;
        if(b.ans == 0) return a;
        p c;
        c.ans = max(a.ans, b.ans);
        c.lft = a.lft;
        c.rft = b.rft;
        c.cntL = a.cntL + (a.lft == b.lft ? b.cntL : 0);
        c.cntR = b.cntR + (a.rft == b.rft ? a.cntR : 0);
        if(a.rft == b.lft) {
            c.ans = max(c.ans, a.cntR + b.cntL);
        }
        //cout << "ANS: " << c.lft << " " << c.rft << " " << c.cntL << " " << c.cntR << " " << c.ans << nl;
        return c;
    }

    void update(int node, int l, int r, int idx, int val) {
        if(l == r) {
            t[node] = p{val,val,1,1,1};
            return;
        }

        int mid = (l + r) >> 1;
        if(idx <= mid) update(node<<1,l,mid,idx,val);
        else update(node<<1|1,mid+1,r,idx,val);

        t[node] = f(t[node<<1], t[node<<1|1]);
    }

    int query(int L, int R) {
        p ans = query(1,0,n-1,L,R);
        return ans.ans;
    }

    p query(int node, int l, int r, int L, int R) {
        if(l > R || r < L) {
            return p{0,0,0,0,0};
        }

        if(l >= L && r <= R) {
            return t[node];
        }

        int mid = (l + r) >> 1;
        return f(query(node<<1,l,mid,L,R), query(node<<1|1,mid+1,r,L,R));
    }
};
int n,q;
int a[N];
void solve(){


    while(cin>>n) {
        if(n == 0) break;
        cin>>q;
        segtree seg;
        seg.n = n;
        for(int i = 0; i < n; i++) {
            cin>>a[i];
            seg.update(1,0,n-1,i,a[i]);
        }
        for(int i = 0; i < q; i++) {
            int l,r;
            cin>>l>>r;
            l--,r--;
            cout << seg.query(l,r) << nl;
        }
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

