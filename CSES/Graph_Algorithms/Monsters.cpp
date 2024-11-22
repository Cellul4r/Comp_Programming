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

const int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
const char d[] = {'U', 'R', 'D', 'L'};
int board[1001][1001], direction[1001][1001];
int si,sj;
queue<pi> Q;
bool a = false;
void answer(int i, int j,vector<vi>& level) {

    cout << "YES" << nl;
    cout << level[i][j] << nl;
    string ans;
    int sr = i, sc = j;
    while(direction[sr][sc] != -1) {
        int k = direction[sr][sc];
        k += 2;
        k %= 4;
        ans += d[(k+2)%4];
        sr += dr[k];
        sc += dc[k];
    }

    reverse(all(ans));
    cout << ans;
}

bool check(int i, int j, vector<vi>& level1, vector<vi>& level2) {

    if(level2[i][j] == -1) return false;
    if(level1[i][j] == -1 || level2[i][j] < level1[i][j]) {
        answer(i,j,level2);
        return true;
    }
    return false;
}
void bfs(int n, int m, vector<vi>& level) {

    if(a) direction[si][sj] = -1;
    while(!Q.empty()) {
        auto ur = Q.front().first, uc = Q.front().second;
        Q.pop();
        // dbg(ur,uc);
        rep(k,4) {
            int vr = ur + dr[k], vc = uc + dc[k];
            if(vr < 0 || vc < 0 || vr >= n || vc >= m || level[vr][vc] != -1 || board[vr][vc] == -1) continue;
            level[vr][vc] = level[ur][uc] + 1;
            if(a) direction[vr][vc] = k;
            Q.push(mp(vr,vc));
        }
    }

}
void solve(){

    int n,m;
    cin>>n>>m;
    vector<vi> level1(n,vi(m,-1)), level2(n,vi(m,-1));
    rep(i,n) {
        string s;
        cin>>s;
        rep(j,m) {
            if(s[j] == '#') {
                board[i][j] = -1; 
            } else if(s[j] == '.') {
                board[i][j] = 0;
            } else if(s[j] == 'M') {
                level1[i][j] = 0;
                Q.push(mp(i,j));
                board[i][j] = 1;
            } else {
                si = i, sj = j;
                level2[i][j] = 0;
                board[i][j] = 2;
            }
        }
    }
    bfs(n,m,level1);
    a = true;
    Q.push(mp(si,sj));
    bfs(n,m,level2);
    
    rep(i,n) {
        if(check(i,0,level1,level2) || check(i,m-1,level1,level2)) {
            return;
        }
    }

    FOR(j,1,m-1) {
        if(check(0,j,level1,level2) || check(n-1,j,level1,level2)) {
            return;
        }
    }
    cout << "NO";
}

int main(){
   ios::sync_with_stdio(false);cin.tie(nullptr);
   int t = 1;
//    cin>>t;
   while(t--)solve();
}