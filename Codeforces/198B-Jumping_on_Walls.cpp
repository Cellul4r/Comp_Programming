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

bool dfs(int i, int j, int n, int k, int water, vector<vector<bool>>& vis, vector<string>& a) {

    if(j >= n) {
        return true;
    }
    if(i < 0 || j < 0 || i >= 2 || j <= water || a[i][j] == 'X' || vis[i][j]) {
        return false;
    }

    vis[i][j] = true;
    // dbg(i,j);
    int ni,nj;
    ni = i, nj = j;
    if(dfs(ni,nj-1,n,k,water+1,vis,a)) {
        vis[i][j] = false;
        return true;
    }
    if(dfs(ni,nj+1,n,k,water+1,vis,a)) {
        vis[i][j] = false;
        return true;
    }
    if(dfs(ni == 0 ? 1 : 0, nj + k,n,k,water+1,vis,a)) {
        vis[i][j] = false;
        return true;
    }
    vis[i][j] = false;
    return false;
}

bool isValid(int i, int j, int water) {

    return !(i < 0 || j < 0 || i >= 2 || j <= water);
}
bool bfs(int n, int k, vector<string>& a) {

    queue<pi> Q;
    vector<vi> level(2, vi(n+k+1,-1));
    Q.push(mp(0,0));
    while(!Q.empty()) {
        int ui = Q.front().first, uj = Q.front().second;
        Q.pop();
        if(uj >= n) {
            return true;
        }
        if(a[ui][uj] == 'X') continue;
        int vi = ui, vj = uj;
        vj = uj-1;
        if(uj > 0 && isValid(vi,vj, level[ui][uj]+1) && level[vi][vj] == -1) {
            level[vi][vj] = level[ui][uj] + 1;
            Q.push(mp(vi,vj));
        }
        vj = uj+1;
        if(isValid(vi,vj, level[ui][uj]+1) && level[vi][vj] == -1) {
            level[vi][vj] = level[ui][uj] + 1;
            Q.push(mp(vi,vj));
        }
        vj = uj+k;
        vi = (ui == 1 ? 0 : 1);
        if(isValid(vi,vj, level[ui][uj]+1) && level[vi][vj] == -1) {
            level[vi][vj] = level[ui][uj] + 1;
            Q.push(mp(vi,vj));
        }
    }

    return false;
}
void solve(){

    int n,k;
    cin>>n>>k;
    vector<string> a(2);
    trav(x,a) cin>>x;

    vector<vector<bool>> vis(2,vector<bool>(n));
    cout << (bfs(n,k,a) ? "YES" : "NO");
}

int main(){
   ios::sync_with_stdio(false);cin.tie(nullptr);
   int t = 1;
//    cin>>t;
   while(t--)solve();
}