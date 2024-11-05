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
const int N = 3e3+1;
const int INF = 1e9+7;
const long long LINF = 1e18+7;

// state of dp is we are tossing to the coins i which now we have j head coin.
ld memo[N][N];
ld recur(int i, int coin, int n, vd& a) {

    if(i == n) {
        // dbg(i);
        // dbg(coin);
        if(coin >= (n+1)/2) return 1;
        else return 0;
    }

    if(memo[i][coin] + 1.00 < 1e-9) return memo[i][coin];
    // choosing head
    auto ans = a[i] * recur(i+1, coin+1, n, a);
    // choosing tail
    ans += (1.00 - a[i]) * recur(i+1, coin, n, a);
    return memo[i][coin] = ans;

}
void solve(){

    int n;
    cin>>n;
    vd a(n);
    trav(x,a) cin>>x;
    // memset(memo, -1.00, sizeof(memo));
    vector<vd> dp(n+1, vd(n+1));
    // dbg(dp[0]);
    rep(i, n) {
        FOR(j, 0, n+1) {
            if(j < n) dp[i+1][j+1] += dp[i][j] * a[i];
            dp[i+1][j] += dp[i][j] * (1.0 - a[i]);
        }
        // dbg(dp[i+1]);
    }
    ld ans = 0.0;
    FOR(i, (n+1)/2, n+1) ans += dp[n][i]; 
    cout << fixed << setprecision(9) << ans;
    // cout << fixed << setprecision(9) << recur(0, 0, n, a);
}

int main(){
   ios::sync_with_stdio(false);cin.tie(nullptr);
   int t = 1;
//    cin>>t;
   while(t--)solve();
}