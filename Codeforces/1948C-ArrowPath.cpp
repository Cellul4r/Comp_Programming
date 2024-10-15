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

int dr[4] = {-1,0,1,0}, dc[4] = {0,1,0,-1};
int n;
int conv(int i, int j) {

    return n*i + j;
}

bool dfs(int u, vector<bool>& vis, set<int> adj[]) {

    dbg(u);
    if(u == 2*n-1) {
        return true;
    }
    vis[u] = true;
    bool flag = false;
    for(auto& v:adj[u]) {
        if(!vis[v]) {
            flag |= dfs(v, vis, adj);
        }
    }
    vis[u] = false;
    return flag;
}
void solve(){

    cin>>n;
    set<int> adj[2*n];
    vector<string> a(2);
    cin>>a[0]>>a[1];
    rep(i,2) {
        rep(j,n) {
            auto id = conv(i,j);
            rep(k,4) {
                int ni = i + dr[k], nj = j + dc[k];
                auto idx = conv(ni,nj);
                if(ni < 0 || nj < 0 || ni >= 2 || nj >= n) continue;
                adj[id].insert(idx);
                if(a[ni][nj] == '>') {
                    adj[idx].insert(conv(ni+dr[1],nj+dc[1]));
                } else {
                    adj[idx].insert(conv(ni+dr[3],nj+dc[3]));
                }
               
            }
        }
    }
    rep(i,2*n) {
        dbg(i);
        dbg(adj[i]);
    }
    vector<bool> b(2*n,false);
    cout << dfs(0, b, adj);
}

int main(){
   ios::sync_with_stdio(false);cin.tie(nullptr);
   int t = 1;
   cin>>t;
   while(t--)solve();
}