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

void setIO(string);

struct segtree {
    
    vector<ll> t;

    void init(int n) {
        t.resize(4 * n);
    }

    ll f(ll a, ll b) {
        return max(a,b);
    }

    void update(int node, int l, int r, int idx, ll v) {
        if(l == r) {
            t[node] = v;
            return;
        }
        int mid = (l + r) >> 1;
        if(idx <= mid) {
            update(node<<1,l,mid,idx,v);
        } else {
            update(node<<1|1,mid+1,r,idx,v);
        }

        t[node] = f(t[node<<1], t[node<<1|1]);
    }

    ll query(int node, int l, int r, int L, int R) {
        if(l > R || r < L) return -INF;
        if(l >= L && r <= R) {
            return t[node];
        }

        int mid = (l + r) >> 1;
        return f(query(node<<1,l,mid,L,R), query(node<<1|1,mid+1,r,L,R));
    }
};
void solve(){
    
    int n;
    ll s,x;
    cin>>n>>s>>x;
    vector<ll> a(n), pre(n+1);
    for(auto &x : a) cin>>x;
    map<ll,vector<int>> cnt;
    ll ans = 0;
    segtree seg;
    seg.init(n+1);
    seg.update(1,0,n,0,-INF);
    for(int i = 0; i < n; i++) {
        seg.update(1,0,n,i+1,a[i]);
    }

    auto f = [&](int l, int r) {
        ll kk = seg.query(1,0,n,l,r);
        //cerr << l << " S " << r << " " << kk << nl;
        if(kk == x){
            return true;
        }

        return false;
    };

    cnt[0].push_back(0);
    for(int i = 1; i <= n; i++) {
        pre[i] = a[i - 1] + pre[i-1];
        auto &k = cnt[pre[i] - s];
        int l = 0, r = k.size() - 1;
        while(l < r) {
            int mid = l + (r - l) / 2;
            if(f(k[mid] + 1,i)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(k.empty() || !f(k[l], i)) l = k.size() + 1;
        int lo = 0, hi = k.size() - 1;
        while(lo < hi) {
            int mid =  lo + (hi - lo + 1) / 2;
            if(f(k[mid] + 1,i)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        if(k.empty() || !f(k[lo],i)) lo = -1;
        cerr << l << " " << lo << nl;
        if(l <= lo) {
            ans += 1ll * (lo - l + 1);
        }
        cnt[pre[i]].push_back(i);
    }
    
    cout << ans << nl;
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

