#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
struct segtree {
    
    typedef int T;
    int t[4*N];

    T f(T a, T b) {
        return max(a,b);
    }

    void update(int node, int l, int r, int i, T v) {
        if(l == r) {
            t[node] = v;
            return;
        }
        int mid = (l + r) >> 1;
        if(i <= mid) {
            update(node<<1,l,mid,i,v);
        } else {
            update(node<<1|1,mid+1,r,i,v);
        }

        t[node] = f(t[node<<1],t[node<<1|1]);
    }

    T query(int node ,int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(l >= L && r <= R) {
            return t[node];
        }
        int mid = (l + r) >> 1;
        return f(query(node<<1,l,mid,L,R), query(node<<1|1,mid+1,r,L,R));
    }
};
typedef long long ll;
void solve() {

    segtree seg;
    int n,m;
    cin>>n>>m;
    vector<ll> preS(n+1), preT(n+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        preS[i] += preS[i-1] + x;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        preT[i] += preT[i-1] + x;
        seg.update(1,0,n-1,i-1,x);
    }
    for(int i=1;i<=m;i++){
        int l,r;
        cin>>l>>r;
        l++,r++;
        cout << (preS[r] - preS[l-1]) / (preT[r] - preT[l-1]) << " ";
        l--,r--;
        cout << seg.query(1,0,n-1,l,r) << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); 
    int t = 1;
    while(t--) solve();
    return 0;
}
