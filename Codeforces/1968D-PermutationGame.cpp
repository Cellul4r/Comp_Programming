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

int n,k,b,s;
vi p;
vl a;
int now = 0;
vector<bool> vis;
vi p1,p2;

ll dfs(int u, vi adj[]) {

    if(now == k-1 || vis[u]) {
        return a[u];
    }

    // dbg(u);
    vis[u] = true;
    ++now;
    ll maxVal = a[u] * (k - now + 1);
    for(auto v:adj[u]) {

        maxVal = max(maxVal,a[u] + dfs(v, adj));
    }

    vis[u] = false;
    --now;

    return maxVal;
}

// ll findSum(int s, int e, vi adj[]) {

//     int i = s, cnt = 0;
//     ll ans = 0;
//     while(i != e) {
//         dbg(i);
//         ++cnt;
//         ans += a[i];
//         for(auto v:adj[i]) {
//             i = v;
//         }
//     }
//     dbg(ans);
//     dbg(cnt);
//     dbg(a[e]);
//     ans += (k - cnt) * a[e];
//     dbg(k-cnt);
//     return ans;
// }
void solve(){

    cin>>n>>k>>b>>s;
    --b,--s;
    p.resize(n);
    a.resize(n);
    vis.resize(n);
    for(auto &x:p) {
        cin>>x;
        --x;
    }
    for(auto &x:a) {
        cin>>x;
    }

    vi adj[n];
    rep(i,n) {
        vis[i] = false;
        adj[i].push_back(p[i]);
    }   

    auto bod = dfs(b,adj);
    // now = 0;
    // rep(i,n) vis[i] = false;
    auto sas = dfs(s,adj);
    // dbg(bod);
    // dbg(sas);
    
    // ll sumB = findSum(b, bod, adj);
    // ll sumS = findSum(s, sas, adj);
    // dbg(sumB);
    // dbg(sumS);

    if(bod > sas) {
        cout << "Bodya";
    } else if(bod < sas) {
        cout << "Sasha";
    } else {
        cout << "Draw";
    }
    cout << nl;
}

int main(){
   ios::sync_with_stdio(false);cin.tie(nullptr);
   int t = 1;
   cin>>t;
   while(t--)solve();
}