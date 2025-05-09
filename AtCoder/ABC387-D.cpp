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
const int N =1e3+1;
const int INF = 1e9+7;
const long long LINF = 1e18+7;

int r,c;
int sr,sc,er,ec;
int board[N][N];
const int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
void solve(){
    
    cin>>r>>c;
    rep(i,r) {
        string s;
        cin>>s;
        rep(j,c) {
            if(s[j] != '#') board[i][j] = 1;
            else board[i][j] = 0;
            if(s[j] == 'S') {
                sr = i, sc = j;
            } else if(s[j] == 'G') {
                er = i, ec = j;
            }
        }
    }
    vector<vector<vi>> level(r, vector(c, vi(3, -1)));
    queue<pair<int,pi>> Q;
    level[sr][sc][1] = level[sr][sc][2] = 0;
    Q.push(mp(0,mp(sr,sc)));
    while(!Q.empty()) {
        int ur = Q.front().second.first, uc = Q.front().second.second;
        int type = Q.front().first;
        //dbg(ur,uc,type);
        Q.pop();
        if(ur == er && uc == ec) {
            cout << level[er][ec][type];
            return;
        }
        if(type != 1) {
            // can move verticaly
            for(int k=0;k<4;k+=2) { 
                int vr = ur + dr[k], vc = uc + dc[k];
                if(vr < 0 || vc < 0 || vr >= r || vc >= c || !board[vr][vc] || level[vr][vc][1] != -1) continue;
                level[vr][vc][1] = level[ur][uc][2] + 1;
                Q.push(mp(1,mp(vr,vc)));
            }
        }
        if(type != 2) {
            for(int k=1;k<4;k+=2){
                int vr = ur + dr[k], vc = uc + dc[k];
                if(vr < 0 || vc < 0 || vr >= r || vc >= c || !board[vr][vc] || level[vr][vc][2] != -1) continue;
                level[vr][vc][2] = level[ur][uc][1] + 1;
                Q.push(mp(2,mp(vr,vc)));
            }
        }
    }
    cout << -1;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t = 1;
    //#ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    //#endif
    //cin>>t;
    while(t--)solve();
}

