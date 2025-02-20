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
const int N =1e2+1;
const int INF = 1e9+7;
const long long LINF = 1e18+7;

const int dr[] = {-1,0,1,0}, dc[] = {0,1,0,-1};
int r,c,n;
int board[N][N];
int cnt = 0;
map<pi,int> save;
int dist[16][16];
int dp[1<<16][16];
int recur(int mask, int prev_) {
    //dbg(mask);
    if(mask == (1 << n) - 1) return 0; 
    if(dp[mask][prev_] != -1) return dp[mask][prev_]; 
    int ans = INF;
    FOR(i,1,n+1) {
        int j = i-1;
        if((mask & (1 << j)) == 0) {
            // we can go
            int nmask = mask | (1 << j);
            ckmin(ans, recur(nmask, i) + dist[prev_][i]);
        }
    }
    //dbg(ans);
    return dp[mask][prev_] = ans;
}
void solve(){
    
    cin>>r>>c>>n;
    save[mp(0,0)] = cnt++;
    vpi node;
    node.pb(mp(0,0));
    rep(i,1<<n) {
        rep(j,n+1) {
            dp[i][j] = -1;
        }
    }
    rep(i,n+1) {
        rep(j,n+1) {
            dist[i][j] = INF;
        }
    }
    rep(i,r) {
        string s;
        cin>>s;
        rep(j,c) {
            if(s[j] == '.') {
                board[i][j] = 0;
            } else if(s[j] == 'S') {
                board[i][j] = 1;
                save[mp(i,j)] = cnt++;
                node.pb(mp(i,j));
            } else if(s[j] == '#') {
                board[i][j] = 2;
            }
        }
    }
    // find all from shrine to shrine and from start point to shrine
    rep(i,n+1) {
        vector<vi> level(r+1, vi(c+1,-1));
        queue<pi> Q;
        Q.push(node[i]);    
        level[node[i].first][node[i].second] = 0;
        while(!Q.empty()) {
            int ur = Q.front().first, uc = Q.front().second;
            Q.pop();
            if(save.find(mp(ur,uc)) != save.end()) {
                dist[i][save[mp(ur,uc)]] = level[ur][uc];
            }
            rep(k,4) {
                int vr = ur + dr[k], vc = uc + dc[k];
                if(vr < 0 || vc < 0 || vr >= r || vc >= c || board[vr][vc] == 2 || level[vr][vc] != -1) continue;
                level[vr][vc] = level[ur][uc] + 1;
                Q.push(mp(vr,vc));
            }
        }
    }

    /*rep(i,n+1) {
        rep(j,n+1) {
            cout << dist[i][j] << " ";
        }
        cout << nl;
    }*/
    int ans = recur(0,0);
    //dbg(ans);
    cout << (ans == INF ? -1 : ans);
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

    return 0;
}

