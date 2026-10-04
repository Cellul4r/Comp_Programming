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
int n;
struct segtree {
    int t[4*N];

    int f(int a, int b) {
        return a + b;
    }
    void update(int idx ,int val) {update(1,0,n-1,idx,val);}
    void update(int node, int l, int r, int idx, int val) {
        if(l == r) {
            t[node] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(idx <= mid) {
            update(node<<1,l,mid,idx,val);
        } else {
            update(node<<1|1,mid+1,r,idx,val);
        }

        t[node] = f(t[node<<1], t[node<<1|1]);
    }

    int query(int L, int R) { return query(1,0,n-1,L,R); }
    int query(int node, int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(l >= L && r <= R) {
            return t[node];
        }

        int mid = (l + r) >> 1;
        return f(query(node<<1,l,mid,L,R), query(node<<1|1,mid+1,r,L,R));
    }
};
int a[N];
int p[N];
bool vis[N];
void dfs(int u) {
    vis[u] = true;
    if(vis[p[u]]) return;
    cout << " " << p[u] + 1;
    //vis[p[u]] = true;
    int nxt = p[u]; 
    dfs(nxt);
}
void solve(){
    
    segtree seg;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
        seg.update(i,1);
    }
    
    for(int i = 0; i < n; i++) {
        int l = 0, r = n - 1;
        int val = a[i]+1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            int k = seg.query(0,mid);
            if(k >= val) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        p[l] = i;
        seg.update(l,0);
    }

    //for(int i = -1; i < n; i++) cout << p[i];

    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            cout << "(" << i + 1;
            dfs(i);
            cout << ") ";
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

