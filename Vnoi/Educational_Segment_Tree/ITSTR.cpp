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
const int NN = 4*N;
const long long INF = 1007050321;
const long long LINF = 1e18+7;

ll poww[N];
struct node {

    ll v = 0;
    ll len = 0;
    ll realLen = 0;
};
struct seg {
    typedef node T;
    T id;
    T f(T a, T b) {
        node k;
        k.v = ((poww[b.len] * a.v) % INF + b.v) % INF;
        k.len = b.len + a.len;
        k.realLen = b.realLen + a.realLen;
        return k;
    }

    vector<T> t;
    void init() {
        t.resize(4*N);
    }
    ll n=N;  // array size
    
    ll findPos(ll node, ll l, ll r, ll pos) {
        if(l == r) {
            return l;
        }

        ll mid = (l + r) >> 1;
        if(pos < t[node<<1].realLen) {
            return findPos(node<<1,l,mid,pos);
        } else {
            return findPos(node<<1|1,mid+1,r,pos - t[node<<1].realLen);
        }
    }

    void modify(ll node, ll l, ll r, ll i, T v) {  // set value at position p
        if(l == r) {
            t[node] = v;
            return;
        }
        ll mid = (l + r) >> 1;
        if(i <= mid) {
            modify(node<<1,l,mid,i,v);
        } else {
            modify(node<<1|1,mid+1,r,i,v);
        }
        t[node] = f(t[node<<1],t[node<<1|1]);
    }
    
    void update(ll node, ll l, ll r, ll pos) {
        t[node].len--;
        if(l == r) {
            t[node].v = t[node].realLen = 0;
            return;
        }
        ll mid = (l + r) >> 1;
        if(pos <= mid) {
            update(node<<1,l,mid,pos);
        } else {
            update(node<<1|1,mid+1,r,pos);
        }
        t[node] = f(t[node<<1],t[node<<1|1]);
    }

    T query(ll node, ll l, ll r, ll L, ll R) { // fold f on interval [l, r)
      if(l > R || r < L) return id;
      if(l >= L && r <= R) {
          return t[node];
      }
      ll mid = (l + r) >> 1;
      return f(query(node<<1,l,mid,L,R), query(node<<1|1,mid+1,r,L,R));
    }
};
void solve(){
    
    poww[0] = 1;
    FOR(i,1,N) {
        poww[i] = (poww[i-1] << 1) % INF;
    }

    string s;
    cin>>s;
    int n = sz(s),m;
    seg sg;
    sg.init();
    rep(i,n) {
        node k;
        k.v = (s[i] == '1' ? poww[0] : 0);
        k.len = 1;
        k.realLen = 1;
        sg.modify(1,0,n-1,i,k);
    }
    cin>>m;
    rep(i,m) {
        char type;
        cin>>type;
        if(type == '-') {
            int pos;
            cin>>pos;
            pos--;
            pos = sg.findPos(1,0,n-1,pos);
            sg.update(1,0,n-1,pos);
        } else {
            int l,r;
            cin>>l>>r;
            l--,r--;
            l = sg.findPos(1,0,n-1,l);
            r = sg.findPos(1,0,n-1,r);
            //dbg(l,r);
            cout << sg.query(1,0,n-1,l,r).v % INF << nl;
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

