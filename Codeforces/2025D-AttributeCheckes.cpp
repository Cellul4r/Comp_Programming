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

void solve(){

    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(auto &x:a) {
        cin>>x;
    }
    vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
    int k = 0,i=0;
    // dbg(a);
    while(i < n){
        if(k == m) break;
        // dbg(a[i]);
        // dbg(dp);
        if(a[i] == 0) {
            ++k;
            rep(j,k+1) {
                if(dp[j][k-j] == -1) dp[j][k-j] = 0;
                // dbg(j);
                // dbg(k-j);
            }
            ++i;
            continue;
        }
        int x;
        if(a[i] < 0) {
            x = abs(a[i]);
            // rep(j,m+1) {
            //     rep(l,m+1) {
            //         if(dp[j][l] != -1 && l >= x) dp[j][l]++;
            //     }
            // }
            FOR(j, x, k+1) {
                if(dp[k-j][j] != -1) dp[k-j][j]++;
            }
        } else {
            x = a[i];
            // rep(j,m+1) {
            //     rep(l,m+1) {
            //         if(dp[j][l] != -1 && j >= x) dp[j][l]++;
            //     }
            // }
            FOR(j, x, k+1) {
                // dbg(j);
                // dbg(k-j);
                if(dp[j][k-j] != -1) dp[j][k-j]++;
            }
        }
        ++i;
    }
    while(i < n) {
        int x;
        if(a[i] < 0) {
            x = abs(a[i]);
            // rep(j,m+1) {
            //     rep(l,m+1) {
            //         if(dp[j][l] != -1 && l >= x) dp[j][l]++;
            //     }
            // }
            FOR(j, x, k+1) {
                if(dp[k-j][j] != -1) dp[k-j][j]++;
            }
        } else {
            x = a[i];
            // rep(j,m+1) {
            //     rep(l,m+1) {
            //         if(dp[j][l] != -1 && j >= x) dp[j][l]++;
            //     }
            // }
            FOR(j, x, k+1) {
                // dbg(j);
                // dbg(k-j);
                if(dp[j][k-j] != -1) dp[j][k-j]++;
            }
        }
        ++i;
    }
    // dbg(dp);
    int ans = 0;
    rep(i,m+1) {
        int sumr = 0;
        int sumc = 0;
        rep(j,m+1) {
            if(dp[j][i] != -1) sumc += dp[j][i];
            if(dp[i][j] != -1) sumr += dp[i][j];
        }
        ans = max({ans,sumc,sumr});
    }
    cout << ans << nl;
}

int main(){
   ios::sync_with_stdio(false);cin.tie(nullptr);
   int t = 1;
//    cin>>t;
   while(t--)solve();
}