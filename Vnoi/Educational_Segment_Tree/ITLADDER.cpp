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
const int NN =1e5+1;
const int INF = 1e9+7;
const long long LINF = 1e18+7;

// Lazy prop segtree, array type is T, lazy op is D
// 3 funcs: comb T, comb D, apply D to T (all assoc)
/*struct lseg {
	typedef pair<ll,pl> T;
	typedef pl D;

	T idT = {0,mp(0,0)}, t[2 * NN];
	D idD = {0,0}, d[2 * NN];
	const ll n = NN;
    const ll m = 1ll * INF;
	T f(T a, T b) {
        return mp((a.first + b.first) % m, mp(min(a.second.first,b.second.first),max(a.second.second,b.second.second)));
    }
	D g(D a, D b) { return mp((a.first+b.first) % m,(a.second+b.second) % m);}
	T h(D a, T b) {
        //dbg(a,b);
        //dbg(b.second);
        ll l = b.second.first, r = b.second.second; 
        ll x = (b.first + (r - l + 1) * a.second % m) % m;
        ll y = (((((r * (r + 1) - l * (l - 1)) + m) % m) * a.first % m) / 2ll + m) % m;
        //dbg(x);
        return mp((x+y)%m, b.second); 
    }

	void apply(ll p, D v) {
		t[p] = h(v, t[p]);
		if(p < n) d[p] = g(v, d[p]);
	}

	void modify(ll p, T v) {
		if(p < n) p += n, t[p] = v;
		while(p /= 2) t[p] = h(d[p], f(t[2 * p], t[2 * p + 1]));
	}

	void modify(ll l, ll r, D v) {
		ll l0 = (l += n), r0 = (r += n);
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) apply(l++, v);
			if(r & 1) apply(--r, v);
		}
		modify(l0,idT), modify(r0-1, idT);
	}

	void push(ll p) {
		for(ll s=26; --s; ) {
			ll i = p >> s;
			apply(2 * i, d[i]);
			apply(2 * i + 1, d[i]);
			d[i] = idD;
		}
	}

	T query(ll l, ll r) {
		l += n, r += n;
		push(l), push(r - 1);
		T resL = idT, resR = idT;
		for(; l < r; l /= 2, r /= 2) {
			if(l & 1) resL = f(resL, t[l++]);
			if(r & 1) resR = f(t[--r], resR);
		}
		return f(resL, resR);
	}
};*/

struct lseg {
    
    typedef pair<ll,pl> T;
    typedef pl D;
    int n;
    const ll m = INF;
    T idT = mp(0,mp(INF,-INF));
    vector<T> t;
    D idD = mp(0,0);
    vector<D> d;

    void init(int n) {
        this->n = NN;
        t.resize(4*n);
        d.resize(4*n);
    }

    T f(T a, T b) {
        ll l = min(a.second.first, b.second.first), r = max(a.second.second,b.second.second);
        return mp(((a.first + b.first) % m), mp(l,r));
    }
    D g(D a, D b) {
        return mp((a.first + b.first) % m, (a.second + b.second) % m);
    }
    T h(D a, T b) {
        //dbg(a,b);
        //dbg(b.second);
        ll l = b.second.first, r = b.second.second; 
        ll x = (b.first + (r - l + 1) * a.second % m) % m;
        ll y = (((r * (r + 1) - l * (l - 1)) / 2ll) * a.first % m);
        //dbg(x);
        return mp((x+y)%m, b.second); 
    }
    
    void apply(int node, D v) {
        t[node] = h(v, t[node]);    
        d[node] = g(v, d[node]);
    }
    
    void push(int node) {
        apply(node<<1,d[node]);
        apply(node<<1|1,d[node]);
        d[node] = idD;
    }

    void update(int i, T v, int node, int l, int r) {
        if(l == r) {
            t[node] = v;
            return;
        }
        int mid = (l + r) >> 1;
        if(i <= mid) {
            update(i,v,node<<1,l,mid);
        } else {
            update(i,v,node<<1|1,mid+1,r);
        }
        t[node] = f(t[node<<1],t[node<<1|1]);
    }

    void update(int node, int l, int r, int L, int R, D v) {
        if(l > R || r < L) return;
        if(l >= L && r <= R) {
            apply(node, v);
        } else {
            push(node);
            int mid = (l + r) >> 1;
            update(node<<1,l,mid,L,R,v); 
            update(node<<1|1,mid+1,r,L,R,v);
            t[node] = f(t[node<<1],t[node<<1|1]);
        }
    }

    T query(int node, int l, int r, int L, int R) {
        if(l > R || r < L) return idT;
        if(l >= L && r <= R) {
            return t[node];
        }
        push(node);
        int mid = (l + r) >> 1;
        return f(query(node<<1, l, mid, L, R), query(node<<1|1, mid+1,r,L,R));
    }
};
void solve(){
    
    int n,m;
    cin>>n>>m;
    lseg seg;
    seg.init(n);
    rep(i,n) {
        seg.update(i,mp(0, mp(i+1,i+1)), 1, 0, n-1);
    }
    rep(i,m) {
        int type;
        cin>>type;
        if(type == 1) {
            ll l,r,a,b;
            cin>>l>>r>>a>>b;
            b -= a * l;
            //b += INF;
            //b %= 1ll * INF;
            l--,r--;
            //dbg(a,b);
            seg.update(1,0,n-1,l,r,mp(a,b));
            /*
            rep(i,n) {
                dbg(seg.query(i,i+1));
            }*/
        } else {
            ll l,r;
            cin>>l>>r;
            l--,r--;
            cout << (seg.query(1,0,n-1,l,r).first + INF) % INF << nl;
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

