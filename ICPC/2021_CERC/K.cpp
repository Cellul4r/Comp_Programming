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
    ll t[4*N];

    ll f(ll a, ll b) {
        return a + b;
    }

    void update(int node, int l, int r, int idx, ll val) {
        if(l == r) {
            t[node] = val;
            return;
        }

        int mid = (l + r) >> 1;
        if(idx <= mid) update(node<<1,l,mid,idx,val);
        else update(node<<1|1,mid+1,r,idx,val);

        t[node] = f(t[node<<1],t[node<<1|1]);

    }

    ll query(int node, int l, int r, int L, int R) {
        if(l > R || r < L) return 0ll;
        if(l >= L && r <= R) return t[node];

        int mid = (l + r) >> 1;
        
        return f(query(node<<1,l,mid,L,R), query(node<<1|1,mid+1,r,L,R));
    }
};
int n,k;
int a[N];
void solve(){

    segtree seg;
    cin>>n;
    for(int i = 0; i < n-1; i++) {
        cin>>a[i];
        seg.update(1,0,n-1,i,a[i]);
    }

    cin>>k;
    //cout << nl;
    auto findAns = [&]() {
        int l = 0, r = n-1;    
        ll ans = LINF;
        while(l <= r) {
            int i = (l + r) >> 1;
            ll x = seg.query(1,0,n-1,0,i-1);
            ll y = seg.query(1,0,n-1,i,n-1);
            ans = min(ans, llabs(x-y));  
            if(x > y) {
                r = i - 1;
            } else if(x <= y) {
                l = i + 1;
            } else {
                break;
            }
        }
        cout << ans << nl;
        /*for(int i = l; i <= r; i++) {
            ll x = seg.query(1,0,n-1,l,i-1);
            ll y = seg.query(1,0,n-1,i,r);

            cout << i << " " << x << " " << y << " " << abs(x-y) << nl;
        }*/
    };

    findAns();
    for(int i = 1; i <= k; i++) {
        int x, val;
        cin>>x>>val;
        x--;
        seg.update(1,0,n-1,x,val);
        // a[x] = val;
        findAns();
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

