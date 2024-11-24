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
const int N =2e5+1;
const int INF = 1e9+7;
const long long LINF = 1e18+7;
 
const int d = 30;
int n,q;
int succ[N][d];
int nxt[N];
vi before[N];
 
void pre() {
    FOR(i,1,d) {
        rep(j,n) {
            succ[j][i] = succ[succ[j][i-1]][i-1];
        }
    }
}
 
int succPath(int u, int k) {
 
    int ans = u;
    rep(i,d) {
        if(k & (1 << i)) {
            ans = succ[ans][i];
        }
    }
    return ans;
}
void solve(){
 
    cin>>n>>q;
    rep(i,n) {
        int x;
        cin>>x;
        --x;
        succ[i][0] = x;
        nxt[i] = x;
        before[x].push_back(i);
    }   
 
    vi cycleId(n,-2);
    vector<map<int,int>> cycles;
 
    // iterate to save each node is in which index of the cycle
    // if it is not belong to the cycle, then it is a tree.
    // if it is cycle there may be has many cycles so we index them.
    rep(i,n) {
        if(cycleId[i] != -2) continue;
        vector<int> path{i};
        int at = i;
        while(cycleId[nxt[at]] == -2) {
            at = nxt[at];
            cycleId[at] = -3;
            path.push_back(at);
        }
 
        map<int,int> cycle;
        bool inCycle = false;
        trav(j, path) {
            inCycle = inCycle || j == nxt[at];
            if(inCycle) {
                cycle[j] = sz(cycle);
            }
            cycleId[j] = inCycle ? sz(cycles) : -1;
        }
        cycles.push_back(cycle);
    }
 
    // preCalculate the distance of the node to its cycle part
    // the start node must be first child of the root(cycle)
    vi cycleDist(n);
    rep(i,n) {
        if(cycleId[nxt[i]] == -1 || cycleId[i] != -1) continue;
        // dbg(i);
        cycleDist[i] = 1;
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            trav(v, before[u]) {
                cycleDist[v] = cycleDist[u] + 1;
                Q.push(v);
            }
        }
    }
 
    // preCalculate the binary lifting
    pre();
    rep(i,q) {
        int u,v;
        cin>>u>>v;
        --u,--v;
        
        if(cycleId[succ[u][d-1]] != cycleId[succ[v][d-1]]) {
            cout << -1 << nl;
            continue;
        }
 
        // case 2 and case 3
        if(cycleId[u] != -1 || cycleId[v] != -1) {
            if(cycleId[u] != -1 && cycleId[v] == -1) {
                cout << -1 << nl;
                continue;
            }
 
            int distU = cycleDist[u];
            int uCycle = succPath(u, distU); 
 
            map<int,int> &cycle = cycles[cycleId[uCycle]];
            int uIdx = cycle[uCycle];
            int vIdx = cycle[v];
 
            int diff = (uIdx <= vIdx ? vIdx - uIdx : sz(cycle) - (uIdx - vIdx));
            cout << distU + diff << nl;
        } else {
            if(cycleDist[u] < cycleDist[v]) {
                cout << -1 << nl;
                continue;
            }
            int diff = cycleDist[u] - cycleDist[v];
            cout << (succPath(u,diff) == v ? diff : -1) << nl;
        }
    }
}
 
int main(){
   ios::sync_with_stdio(false);cin.tie(nullptr);
   int t = 1;
//    cin>>t;
   while(t--)solve();
}