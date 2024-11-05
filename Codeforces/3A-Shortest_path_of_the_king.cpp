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

const int dr[8] = {-1,-1,-1,0,1,1,1,0}, dc[8] = {-1,0,1,1,1,0,-1,-1};
const string out[8] = {"LU", "U", "RU", "R", "RD", "D", "LD", "L"};
void solve(){

    string s,t;
    cin>>s>>t;
    int sr,sc,er,ec;
    sr = ('8' - s[1]);
    sc = s[0] - 'a';
    er = ('8' - t[1]);
    ec = t[0] - 'a';
    queue<pi> Q;
    vector<vector<string>> level(8, vector<string>(8, ""));
    vector<vpi> par(8, vpi(8));
    vector<string> ans;
    dbg(sr,sc);
    dbg(er,ec);
    par[sr][sc] = mp(sr,sc);
    Q.push(mp(sr,sc));
    while(!Q.empty()) {
        auto ur = Q.front().first, uc = Q.front().second;
        Q.pop();
        if(ur == er && uc == ec) break;
        rep(k,8) {
            auto vr = ur + dr[k], vc = uc + dc[k];
            if(vr < 0 || vc < 0 || vr >= 8 || vc >= 8 || level[vr][vc] != "") continue;
            par[vr][vc] = mp(ur,uc);
            level[vr][vc] = out[k];
            Q.push(mp(vr,vc));
        }
    }
    while(er != sr || ec != sc) {
        ans.emplace_back(level[er][ec]);
        tie(er,ec) = par[er][ec];
    }
    reverse(all(ans));
    cout << sz(ans) << nl;
    trav(x,ans) cout << x << nl;
}

int main(){
   ios::sync_with_stdio(false);cin.tie(nullptr);
   int t = 1;
//    cin>>t;
   while(t--)solve();
}