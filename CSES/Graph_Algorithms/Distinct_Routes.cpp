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
const int N =1e5+1,S=501;
const int INF = 1e9+7;
const long long LINF = 1e18+7;
 
struct dinic {
 
	struct edge {ll b, cap, flow, flip;};
	vector<edge> g[S+2];
    bool vis[S+2];
    vector<pi> cut;
    vi path;

	ll ans=0, d[S+2], ptr[S+2];
	void add_edge (ll a, ll b, ll cap) {
		g[a].push_back({b, cap, 0, g[b].size()});
		g[b].push_back({a, 0, 0, g[a].size()-1});
	}
	ll dfs (ll u, ll flow=LLONG_MAX) {
		if (u==S+1 || !flow) return flow;
		while (++ptr[u] < g[u].size()) {
			edge &e = g[u][ptr[u]];
			if (d[e.b] != d[u]+1) continue;
			if (ll pushed = dfs(e.b, min(flow, e.cap-e.flow))) {
				e.flow += pushed;
				g[e.b][e.flip].flow -= pushed;
				return pushed;
			}
		}
		return 0;
    }
 
    void findPath(int u) {
        path.pb(u);
        trav(v,g[u]) {
            if(v.flow > 0) {
                // dbg(u,v.b,v.flow);
                v.flow = 0;
                findPath(v.b);
                break;
            }
        }
    }
    void dfs2(int u) {
        vis[u] = true;
        trav(vw, g[u]) {
            int v = vw.b;
            if(vw.cap > vw.flow && !vis[v]) {
                dfs2(v);
            } 
        }
    }
 
    void minCut() {
        rep(i,S+2) {
            if(!vis[i]) continue;
            trav(v,g[i]) {
                if(!vis[v.b] && v.cap > 0) {
                    cut.pb(mp(i,v.b));
                }
            }
        }
    }
 
	void calc() {
		do {
			vector<ll> q {S};
			memset(d, 0, sizeof d);
			ll i = -(d[S] = 1);
			while (++i<q.size() && !d[S+1])
				for (auto e: g[q[i]])
					if (!d[e.b] && e.flow<e.cap) {
						q.push_back(e.b);
						d[e.b] = d[q[i]]+1;
					}
			memset(ptr, -1, sizeof ptr);
			while(ll pushed=dfs(S)) ans+=pushed;
		} while (d[S+1]);
	}
};
 
int check(int u, int n) {
    if(u == 1) {
        u = S;
    } else if(u == n) {
        u = S+1;
    } 
    return u;
}
void solve(){
 
    int n,m;
    cin>>n>>m;
    dinic di;
    rep(i,m) {
        int a,b;
        cin>>a>>b;
        a = check(a,n);
        b = check(b,n);
        di.add_edge(a,b,1);
    }
    di.calc();
    cout << di.ans << nl;
    rep(i,di.ans){
        di.path.clear();
        di.findPath(S);
        cout << sz(di.path) << nl;
        trav(x,di.path) {
            if(x == S) x = 1;
            else if(x == S+1) x = n;
            cout << x << " ";
        }
        cout << nl;
    }
}
 
int main(){
   ios::sync_with_stdio(false);cin.tie(nullptr);
   int t = 1;
//    cin>>t;
   while(t--)solve();
}