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

const string word = "ALLIZZWELL";
bool dfs(int i, int j, int n, int m, vector<string> board, vector<vector<bool>>& vis, int now) {

    if(now == sz(word)) {
        return true;
    }
    // cout << i << " " << j << nl;
    vis[i][j] = true;
    for(int r=-1;r<=1;++r) {
        for(int c=-1;c<=1;++c) {
            auto ni = i + r, nj = j + c;
            if(ni < 0 || nj < 0 || ni >= n || nj >= m || vis[ni][nj] || word[now] != board[ni][nj]) continue;
            if(dfs(ni,nj,n,m,board,vis,now+1)) {
                return true;
            }
        }
    }
    vis[i][j] = false;
    return false;
}
void solve(){

    int n,m;
    cin>>n>>m;

    vector<string> board(n);
    rep(i,n) {
        cin>>board[i];
    }
    vector<vector<bool>> vis(n, vector<bool>(m));
    for(int i=0;i<n;++i) {
        for(int j=0;j<m;++j) {
            if(word[0] == board[i][j] && dfs(i,j,n,m,board,vis,1)) {
                cout << "YES" << nl;
                return;
            }
        }
    }

    cout << "NO" << nl;
}

int main(){
   ios::sync_with_stdio(false);cin.tie(nullptr);
   int t = 1;
   cin>>t;
   while(t--)solve();
}