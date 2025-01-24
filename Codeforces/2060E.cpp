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
const int N =2e5+2;
const int INF = 1e9+7;
const long long LINF = 1e18+7;

const int NN = N;
//DSU
struct DSU {

    ll parent[NN], sz[NN];
    ll find(ll a){ return a == parent[a] ? a : parent[a] = find(parent[a]); }
    void merge(ll u, ll v) {
        u = find(u), v=find(v);
        if (u!=v) {
            if (sz[u]<sz[v]) swap(u, v);
            sz[u] += sz[v];
            parent[v] = u;
        }
    }
};

set<int> adj[N];
vi bdj[N];
bool vis[N],vis2[N];
ll ans;
void dfs(int u, DSU& g) {

    vis[u] = true; 
    //dbg(u);
    vi del;
    trav(v,adj[u]) {
        if(!vis[v] && g.find(u) != g.find(v)) {
            //dbg(u,v);
            del.pb(v);
            adj[v].erase(u);
            ans++;
        } else if(!vis[v]){
            dfs(v,g);
        }
    }
    trav(x,del) {
        adj[u].erase(x);
    }
}
void dfs2(int u, DSU& f) {

    vis2[u] = true;
    //dbg(u);
    trav(v,bdj[u]) {
        //dbg(v);
        if(!vis2[v] && f.find(u) != f.find(v)) {
            //dbg(u,v);
            ans++;
        }
        if(!vis2[v]) {
            dfs2(v,f);
        }
    }
}
void solve(){
    
    ans = 0;
    int n,f,g;
    cin>>n>>f>>g;
    DSU F,G;
    rep(i,n) {
        F.parent[i+1] = i+1;
        F.sz[i+1] = 1;
        G.parent[i+1] = i+1;
        G.sz[i+1] = 1;
    }

    rep(i,f) {
        int u,v;
        cin>>u>>v;
        adj[u].ins(v);
        adj[v].ins(u);
    }

    rep(i,g) {
        int u,v;
        cin>>u>>v;
        bdj[u].pb(v);
        bdj[v].pb(u);
        G.merge(u,v);
    }
    
    rep(i,n) {
        if(!vis[i+1]) {
            dfs(i+1,G);
        }
    }

    rep(i,n) {
        trav(v,adj[i+1]) {
            //dbg(i+1,v);
            F.merge(i+1,v);
        }
    }
    
    rep(i,n) {
        if(!vis2[i+1]) {
            dfs2(i+1,F);
        }
    }
    cout << ans << nl;

    FOR(i,1,n+1){
        adj[i].clear();
        bdj[i].clear();
        vis[i] = false;
        vis2[i] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t = 1;
    //#ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    //#endif
    cin>>t;
    while(t--)solve();
}

