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
struct segtree {

    int t[4*N];

    int f(int a, int b) { return max(a,b); }

    void update(int node, int l, int r, int idx, int val) {
        if(l == r) {
            t[node] = f(t[node],val);
            return;
        }

        int mid = (l + r) >> 1;
        if(idx <= mid) {
            update(node<<1,l,mid,idx,val);
        } else {
            update(node<<1|1,mid+1,r,idx,val);
        }
        t[node] = f(t[node<<1],t[node<<1|1]);
    }

    int query(int node, int l, int r, int L, int R) {
        if(l > R || r < L) return 1;
        if(l >= L && r <= R) {
            return t[node];
        }
        int mid = (l + r) >> 1;
        return f(query(node<<1,l,mid,L,R), query(node<<1|1,mid+1,r,L,R));
    }
};
int n,q;
// trick each we gradually increase the range query of R,R+1,...
// then when we go to that range R we have to know what value divisor does it has
// where is the last position of this divisor j we have seen
// at last[r] we have this divisor j we must find some another
// to get this gcd value = j
// just save it in last[r]
// then find max in range query[l,r]
vector<pi> save[N], query[N];
vector<int> divi[N];
int idx[N];
int a[N], ans[N];
void solve(){

    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    cin>>q;
    for(int i = 0; i < q; i++) {
        int l, r; cin>>l>>r;
        l--,r--;
        query[r].push_back({l,i});
    }

    // save all divisor in O(nlogn)
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            // j divisible by i
            divi[j].push_back(i);
        }
    }

    // create save[N] for at pos i each divisor j where does the last pos before this occur to get the gcd
    memset(idx, -1, sizeof idx);
    for(int i = 0; i < n; i++) {
        for(auto &j : divi[a[i]]) {
            if(idx[j] != -1) {
                save[i].push_back(make_pair(idx[j], j));
            }
            idx[j] = i;
        }
    }

    segtree seg;
    for(int r = 0; r < n; r++) {
        for(auto& [i, j] : save[r]) {
            seg.update(1,0,n-1,i,j);
        }

        for(auto &[l, i] : query[r]) {
            ans[i] = seg.query(1,0,n-1,l,r);            
        }
    }

    for(int i = 0; i < q; i++) {
        cout << ans[i] << nl;
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

