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

bool check(int n, int level, int a, int b) {
    
    //dbg(a,b);
    int x = n / 2 - level;
    int y = x;
    int len = 2 * (level + 1);
    if(x == a && y <= b && b <= y + len - 1) {
        return true;
    }
    if(y == b && x <= a && a <= x + len - 1) {
        return true;
    }
    x = n - x + 1;
    y = x;
    if(x == a && y - len + 1 <= b && b <= y) {
        return true;
    }
    if(y == b && x - len + 1 <= a && a <= x) {
        return true;
    }
    return false;
}
void solve(){
    
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    // x1 a, y1 b, x2 c, y2 d
    int level1=0,level2=0;
    if(a > n / 2) {
        a = n - a + 1;
    }
    if(b > n / 2) {
        b = n - b + 1;
    }
    if(c > n / 2) {
        c = n - c + 1;
    }
    if(d > n / 2) {
        d  = n - d + 1;
    }
    //dbg(a,b,c,d);
    if(check(n, n / 2 - a, a, b)) {
        level1 = n / 2 - a;
    } else if(check(n, n / 2 - b, a, b)) {
        level1 = n / 2 - b;
    } 
    if(check(n, n / 2 - c, c, d)) {
        level2 = n / 2 - c;
    } else if(check(n, n / 2 - d, c, d)) {
        level2 = n / 2 - d;
    }
    //dbg(level1, level2);
    cout << abs(level1 - level2) << nl;
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

    return 0;
}

