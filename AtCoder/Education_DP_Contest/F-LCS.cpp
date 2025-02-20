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
const int N =3e3+1;
const int INF = 1e9+7;
const long long LINF = 1e18+7;

// string recur(int i, int j, int n, int m, string& s, string& t, vector<vector<string>>& dp) {

//     if(i == n || j == m) {
//         return "";
//     }
    
//     string ans = recur(i+1, j+1, n, m, s, t, dp);
//     if(s[i] == t[j]) {
//         string k = s[i] + recur(i+1, j+1, n, m, s, t, dp);
//     }
// }

int dp[N][N];
pi par[N][N];
char save[N][N];
void solve(){

    string s,t;
    cin>>s>>t;
    int n = sz(s), m = sz(t);
    
    // dp[i][j] = ?
    // if(s[i] == t[j]) dp[i][j] = dp[i-1][j-1] + 1
    // dp[i][j] = 
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dp[i][j] = dp[i-1][j-1];
            par[i][j] = mp(i-1,j-1);
            if(s[i-1] == t[j-1]) {
                ckmax(dp[i][j], dp[i-1][j-1] + 1);
                save[i][j] = s[i-1];
            }
            if(dp[i-1][j] > dp[i][j]) {
                dp[i][j] = dp[i-1][j];
                par[i][j] = mp(i-1,j);
            }
            if(dp[i][j-1] > dp[i][j]) {
                dp[i][j] = dp[i][j-1];
                par[i][j] = mp(i,j-1);
            }
        }
    }

    string ans;
    /*rep(i,n+1) {
        rep(j,m+1) {
            cout << par[i][j].first << "-" << par[i][j].second << " ";
        }
        cout << nl;
    }*/
    
    int x = n, y = m;
    while(x != 0 && y != 0) {
        if(save[x][y] != '\0') ans += save[x][y];
        pi k = par[x][y];
        x = k.first;
        y = k.second;
    }
    
    reverse(all(ans));
    cout << ans;
}

int main(){
   ios::sync_with_stdio(false);cin.tie(nullptr);
   int t = 1;
//    cin>>t;
   while(t--)solve();
}
