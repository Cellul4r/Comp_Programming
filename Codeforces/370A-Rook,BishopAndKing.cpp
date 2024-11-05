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

const int dr[] = {-1,-1,-1,0,1,1,1,0}, dc[] = {-1,0,1,1,1,0,-1,-1};
int bfs(int sr, int sc, int er, int ec) {

    vector<vi> level(9, vi(9,-1));
    level[sr][sc] = 0;
    queue<pi> Q;
    Q.push(mp(sr,sc));
    while(!Q.empty()) {
        int ur = Q.front().first, uc = Q.front().second;
        Q.pop();

        if(ur == er && uc == ec) {
            break;
        }
        rep(k,8) {
            int vr = ur + dr[k], vc = uc + dc[k];
            if(vr < 0 || vc < 0 || vr >= 9 || vc >= 9) continue;
            if(level[vr][vc] == -1) {
                level[vr][vc] = level[ur][uc] + 1;
                Q.push(mp(vr,vc));
            }
        }
    }

    return level[er][ec];
}
void solve(){

    int sr,sc,er,ec;
    cin>>sr>>sc>>er>>ec;
    if(sr == er && sc == ec) {
        cout << "0 0 0" << nl;
        return;
    }
    // part1
    if(sr == er || sc == ec) {
        cout << 1 << " ";
    } else {
        cout << 2 << " ";
    }
    // part2
    if(abs(er-ec) % 2 == 0 && abs(sr-sc) % 2 == 1) {
        cout << 0 << " ";
    } else if(abs(er-ec) % 2 == 1 && abs(sr-sc) % 2 == 0) {
        cout << 0 << " ";
    } else if(abs(sr-er) == abs(sc-ec)) {
        cout << 1 << " ";
    } else {
        cout << 2 << " ";
    }

    // part3
    cout << bfs(sr,sc,er,ec);
}

int main(){
   ios::sync_with_stdio(false);cin.tie(nullptr);
   int t = 1;
//    cin>>t;
   while(t--)solve();
}