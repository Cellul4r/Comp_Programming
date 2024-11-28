/*
ID: serious6
TASK: 
LANG: C++
*/
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
const string file = "";

struct cow {
    int x,y;
    int idx;
};

bool comp1(const cow& x, const cow& y) {
    return x.x < y.x;
}
bool comp2(const cow& x, const cow& y) {

    return x.y < y.y;
}

void solve(){

    int n;
    cin>>n;
    int cnt = 0;
    
    vector<cow> north,east;
    rep(i,n) {
        string s;
        cin>>s;
        int a,b;
        cin>>a>>b;
        if(s == "N") {
            north.pb({a,b,i});
        } else {
            east.pb({a,b,i});
        }
    }
    sort(all(north), comp1);
    sort(all(east), comp2);

    vi grass(n,-1);
    trav(n, north) {
        trav(e, east) {
            if(n.x > e.x && n.y < e.y) {
                int distN = e.y - n.y;
                int distE = n.x - e.x;

                if(distN < distE && grass[e.idx] == -1) {
                    grass[e.idx] = n.x;
                }

                if(distN > distE && grass[e.idx] == -1) {
                    grass[n.idx] = e.y;
                    break;
                }
            }
        }
    }

    vi dist(n,-1);
    trav(n, north) {
        if(grass[n.idx] != -1) {
            dist[n.idx] = grass[n.idx] - n.y;
        }
    }

    trav(e, east) {
        if(grass[e.idx] != -1) {
            dist[e.idx] = grass[e.idx] - e.x;
        }
    }

    trav(x, dist) {
        cout << (x == -1 ? "Infinity" : to_string(x)) << nl;
    }
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    //     freopen((file + ".in").c_str(), "r", stdin);
    //     freopen((file + ".out").c_str(), "w", stdout);
    // #endif
    int t = 1;
    //cin>>t;
    while(t--)solve();
}