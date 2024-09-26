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
const int N =1e6+4;
const ll M = 1e9+6;
const int INF = 1e9+7;
const long long LINF = 1e18+7;

struct point {

    ll maxInit, maxFlipped;
    int idxInit, idxFlipped;
};

struct seg {

    typedef point T;
    vector<T> t;
    vector<int> lazy;

    void init(int n) {
        t.resize(4*n);
        lazy.resize(4*n);
    }
    T f(T a, T b) {
        T c;
        // dbg(a);
        // dbg(b);
        // initial value
        if(a.maxInit > b.maxInit) {
            c.maxInit = a.maxInit;
            c.idxInit = a.idxInit;
        } else if(a.maxInit < b.maxInit) {
            c.maxInit = b.maxInit;
            c.idxInit = b.idxInit;
        } else {
            c.maxInit = a.maxInit;
            c.idxInit = min(a.idxInit, b.idxInit);
        }

        if(a.maxFlipped > b.maxFlipped) {
            c.maxFlipped = a.maxFlipped;
            c.idxFlipped = a.idxFlipped;
        } else if(a.maxFlipped < b.maxFlipped) {
            c.maxFlipped = b.maxFlipped;
            c.idxFlipped = b.idxFlipped;
        } else {
            c.maxFlipped = a.maxFlipped;
            c.idxFlipped = min(a.idxFlipped, b.idxFlipped);
        }

        return c;
    }

    void build(ll node, ll l, ll r, vector<pair<int,ll>>& a) {
        if(l == r) {
            t[node].maxInit = a[l].second;
            t[node].idxInit = a[l].first;
            t[node].maxFlipped = (a[l].second * M) % INF;
            t[node].idxFlipped = a[l].first;
            return;
        }
        ll mid = (l + r) >> 1;
        build(node<<1,l,mid,a);
        build(node<<1|1,mid+1,r,a);
        t[node] = f(t[node<<1], t[node<<1|1]);
    }

    void apply(ll node, ll l, ll r) {
        if(!lazy[node]) return;
        swap(t[node].maxFlipped,t[node].maxInit);
        swap(t[node].idxInit, t[node].idxFlipped);
        if(l != r) {
            lazy[node<<1] ^= 1;
            lazy[node<<1|1] ^= 1;
        }
        lazy[node] = 0;
    }

    void update(ll node, ll l, ll r, ll qL, ll qR) {
        apply(node, l, r);
        if(r < qL || l > qR) return;
        if(l >= qL && r <= qR) {
            lazy[node] ^= 1;
            apply(node, l, r);
        } else {
            ll mid = (l+r) >> 1;
            update(node<<1,l,mid,qL,qR);
            update(node<<1|1,mid+1,r,qL,qR);
            t[node] = f(t[node<<1],t[node<<1|1]);
        }
    }


};
void solve(){

    seg k;
    int n;
    cin>>n;
    k.init(n);
    vector<pair<int,ll>> a(n);
    for(int i=0;i<n;++i) {
        a[i].first = i+1;
        cin>>a[i].second;
    }
    k.build(1,0,n-1,a);
    int q;
    cin>>q;
    ll ans = 0;
    rep(i,q) {
        ll l,r;
        cin>>l>>r;
        --l,--r;
        // dbg(k.t[1].maxInit);
        k.update(1,0,n-1,l,r);
        // rep(j,n) {
        //     auto x = k.query(1,0,n-1,j,j);
        //     dbg(x);
        // }
        // auto x = k.query(1,0,n-1,0,n-1);
        // dbg(k.t[1].maxInit);
        ans += k.t[1].idxInit;
    }
    cout << ans << endl;
}

int main(){
ios::sync_with_stdio(false);cin.tie(nullptr);
int t = 1;
cin>>t;
   FOR(i,1,t+1) {cout << "Case #" << i << ": ";solve();}
}