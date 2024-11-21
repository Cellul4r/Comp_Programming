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
const int INF = 1e9;
const long long LINF = 1e18+7;

int idx(string s) {
    if(s == "BG") return 0;
    if(s == "BR") return 1;
    if(s == "BY") return 2;
    if(s == "GR") return 3;
    if(s == "GY") return 4;
    if(s == "RY") return 5;
    return -1;
}
void solve(){

    int n,q;
    cin>>n>>q;
    vector<vi> pre(n+1, vi(6));
    vector<string> a(n);
    rep(i,n) {
        string s;
        cin>>s;
        a[i] = s;
        int k = idx(s);
        rep(j,6) {
            pre[i+1][j] = pre[i][j]; 
        }
        pre[i+1][k]++;
        
    }
    // dbg(pre);
    rep(i,q) {
        int x,y;
        cin>>x>>y;
        if(x > y) swap(x,y);
        if(x == y) {
            cout << 0 << nl;
        } else if(a[x-1][0] == a[y-1][0] || a[x-1][0] == a[y-1][1] || a[x-1][1] == a[y-1][0] || a[x-1][1] == a[y-1][1]){
            cout << y-x << nl;
        } else {
            int b = idx(a[x-1]);
            int c = idx(a[y-1]);
            int cnt = y-x+1- (pre[y][b] - pre[x-1][b]) - (pre[y][c] - pre[x-1][c]);
            if(cnt > 0) {
                cout << y-x << nl;
            } else {
                int ans = INF;
                int lo = y+1, hi = n;
                while(lo <= hi) {
                    auto mid = lo + (hi - lo) / 2;
                    int k = mid-y- (pre[mid][b] - pre[y][b]) - (pre[mid][c] - pre[y][c]);
                    if(k > 0) {
                        ckmin(ans, abs(x-mid) + abs(y-mid));
                        hi = mid-1;
                    } else {
                        lo = mid+1;
                    }
                }
                lo = 1,hi=x-1;
                while(lo <= hi) {
                    auto mid = lo + (hi - lo) / 2;
                    int k = x-mid - (pre[x-1][b] - pre[mid-1][b]) - (pre[x-1][c] - pre[mid-1][c]);
                    if(k > 0) {
                        ckmin(ans, abs(x-mid) + abs(y-mid));
                        lo = mid+1;
                    } else {
                        hi = mid-1;
                    }
                }
                    // dbg(ans);
                    // dbg(ans2);
                if(ans != INF) {
                    cout << ans << nl;
                } else {
                    cout << -1 << nl;
                }
            }
        }
    }
}

int main(){
   ios::sync_with_stdio(false);cin.tie(nullptr);
   int t = 1;
   cin>>t;
   while(t--)solve();
}