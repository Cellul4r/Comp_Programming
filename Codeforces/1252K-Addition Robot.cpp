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
const ll INF = 1e15+5;
const int N = 1e5+5;
const ll mod = 1000000007;

string s;
struct mat {
    ll m[2][2] = {{0,0},{0,0}};
    mat operator *(const mat& other) {
        mat product;
        for(int i=0;i<2;++i) {
            for(int j=0;j<2;++j) {
                for(int k=0;k<2;++k) {
                    product.m[i][k] += (m[i][j] * other.m[j][k]) % mod;
                }
            }
        }
        return product;
    }

    void change() {
        swap(m[0][0],m[1][1]);
        swap(m[0][1],m[1][0]);
    }
};

mat A,B,identity;
mat seg[4*N];
int lazy[4*N];

void build(ll node, ll l, ll r) {
    if(l == r) {
        if(s[l] == 'A') {
            seg[node] = A;
        } else {
            seg[node] = B;
        }
        return;
    }
    ll mid = (l + r) / 2;
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    seg[node] = seg[node*2] * seg[node*2+1];
}
void apply(ll node) {
    if(!lazy[node]) return;
    lazy[node] = 0;
    lazy[2*node+1] = lazy[2*node+1] ^ 1;
    lazy[2*node] = lazy[2*node] ^ 1;
    seg[2*node].change();
    seg[2*node+1].change();
}

void query1(ll node, ll l, ll r, ll qL, ll qR) {
    if(r < qL || l > qR) return;
    if(l >= qL && r <= qR) {
        seg[node].change();
        lazy[node] ^= 1;
    } else {
        apply(node);
        ll mid = (l + r) / 2;
        query1(2*node,l,mid,qL,qR);
        query1(2*node+1,mid+1,r,qL,qR);
        seg[node] = seg[node*2] * seg[node*2+1];
    }
}

mat query2(ll node, ll l, ll r, ll qL, ll qR) {

    if(r < qL || l > qR) return identity;
    else if(l >= qL && r <= qR) return seg[node];
    apply(node);
    ll mid = (l + r) / 2;
    return query2(2*node,l,mid,qL,qR) * query2(2*node+1,mid+1,r,qL,qR);
}
void solve() {

    A.m[0][0] = A.m[1][0] = A.m[1][1] = 1;
    A.m[0][1] = 0;
    B.m[0][0] = B.m[0][1] = B.m[1][1] = 1;
    B.m[1][0] = 0;
    identity.m[0][0] = identity.m[1][1] = 1;
    identity.m[0][1] = identity.m[1][0] = 0;
    int n,q;
    cin>>n>>q;
    cin>>s;

    build(1,0,n-1);
    while(q--) {
        int p;
        cin>>p;
        if(p == 1) {
            ll l,r;
            cin>>l>>r;
            --l;
            --r;
            query1(1,0,n-1,l,r);
        } else{
            ll l,r,a,b;
            cin>>l>>r>>a>>b;
            --l;
            --r;
            auto ans = query2(1,0,n-1,l,r);
            /*for(int i=0;i<2;++i) {
                for(int j=0;j<2;++j) {
                    cout << ans.m[i][j] << " : ";
                }
                cout << endl;
            } */
            ll newA = (a * ans.m[0][0] % mod + b * ans.m[1][0] % mod) % mod; 
            ll newB = (a * ans.m[0][1] % mod + b * ans.m[1][1] % mod) % mod;
            cout << newA << " " << newB << endl;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    //cin>>t;
    //sf("%d",&t); 
    while(t--) {
        solve();
    }
    return 0;
}
/*
 */
