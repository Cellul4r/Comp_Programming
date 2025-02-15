#include<bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '"' << x << '"';}
void __print(const string &x) {cerr << '"' << x << '"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x);
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
//#ifdef DEBUG
#define dbg(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << endl;
//#else
//#define dbg(x...)
//#endif
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define rep(i, a) for(int i=0;i<a;++i)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
//#define f first
//#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define ins insert
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const char nl = '\n';
const int N =1e5+1;
const int INF = 1e9+7;
const long long LINF = 1e18+7;

struct node {
    
    ll add = 0, mul = 1, st = -1;
};
struct lseg {
    
    typedef ll T;
    typedef node D;

    T idT = 0;
    vector<T> t;
    D idD;
    vector<D> d;
    const ll m = INF; 
    void init() {
        t.resize(4*N);
        d.resize(4*N);
    }
    void update(ll i, ll v, ll node, ll l, ll r) {
        if(l == r) {
            t[node] = v;
            return;
        }
        ll mid = (l + r) >> 1ll;
        if(i <= mid) {
            update(i,v,node<<1,l,mid);
        } else {
            update(i,v,node<<1|1,mid+1,r);
        }
        t[node] = (t[node<<1] + t[node<<1|1]) % m;
    }
    
    void apply(ll node, ll len, D v) {
        if(v.st != -1) {
            t[node] = len * v.st % m;
            d[node].st = v.st;
            d[node].add = 0;
            d[node].mul = 1;
        } else {
            t[node] = (t[node] * v.mul) % m;
            t[node] = (t[node] + len * v.add) % m;
            if(d[node].st != -1) {
                d[node].st = (d[node].st * v.mul + v.add) % m;
            } else {
                d[node].mul = d[node].mul * v.mul % m; 
                d[node].add = (d[node].add * v.mul % m + v.add) % m;
            }
        }
    }

    void push(ll node, ll l, ll r) {
        ll mid = (l + r) >> 1;
        apply(node<<1, mid - l + 1, d[node]);
        apply(node<<1|1, r - mid, d[node]);
        d[node] = idD;
    }

    void update(ll node, ll l, ll r, ll L, ll R, D v) {
        //dbg(l,r);
        if(l > R || r < L) return;
        if(l >= L && r <= R) {
            apply(node, r - l + 1, v);
        } else {
            push(node, l, r);
            ll mid = (l + r) >> 1;
            update(node<<1, l, mid ,L,R,v);
            update(node<<1|1, mid+1, r,L,R,v);
            t[node] = (t[node<<1] + t[node<<1|1]) % m;
        }
    }

    ll query(ll node, ll l, ll r, ll L, ll R) {
        if(l > R || r < L) return idT;
        if(l >= L && r <= R) {
            return t[node];
        }
        push(node, l, r);
        ll mid = (l + r) >> 1;
        return (query(node<<1,l,mid,L,R) + query(node<<1|1,mid+1,r,L,R)) % m;
    }
};
void solve(){
    
    int n,m;
    cin>>n>>m;
    lseg seg;
    seg.init();
    rep(i,n) {
        ll x;
        cin>>x;
        seg.update(i,x,1,0,n-1);
    }
    rep(i,m) {
        int type;
        cin>>type;
        ll l,r;
        cin>>l>>r;
        l--,r--;
        if(type <= 3) {
            ll x;
            cin>>x;
            node k;
            if(type == 1) k.add = x;
            else if(type == 2) k.mul = x;
            else k.st = x;
            seg.update(1,0,n-1,l,r, k);
            /*rep(j,n) {
                dbg(seg.query(1,0,n-1,j,j));
            }*/
        } else {
            cout << (seg.query(1,0,n-1,l,r)) << nl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t = 1;
    //#ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    //#endif
    //cin>>t;
    while(t--)solve();

    return 0;
}

