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
    vector<string> a(n);
    vi cnt(n);
    vi cnt2(n);
    deque<int> now;
    rep(i,n) {
        now.pb(i);
        cin>>a[i];
        F0Rd(j,sz(a[i])) {
            if(a[i][j] != '0') break;
            cnt[i]++;
        }
        cnt2[i] = sz(a[i]);
    }

    auto comp = [&](int i, int j) {
        if(cnt[i] != cnt[j]) {
            return cnt[i] > cnt[j];    
        }
        return cnt2[i] - i > cnt2[j] - j;
    };
    sort(all(now), comp);
    int anna = 1;
    bool flag = true;
    while(flag || sz(now) > 1) {
        //dbg(now);
        flag = false;
        if(anna) {
            int v = now.front();
            //dbg(v, cnt2[v], cnt[v]);
            cnt2[v] -= cnt[v];
            cnt[v] = 0;
            now.pop_front();
            now.pb(v);
        } else {
            int u = now.front();
            int v = now.back();
            //dbg(u,v,cnt[u],cnt2[u],cnt[v],cnt2[v]);
            now.pop_front();
            now.pop_back();
            cnt2[u] += cnt2[v];
            cnt[u] = cnt[v];
            now.pb(u);
        }
        anna ^= 1;
    }

    //dbg(now);
    int k = now.front();
    //dbg(cnt2[k]);
    k = cnt2[k];
    cout << (k-1 < m ? "Anna" : "Sasha") << nl;
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

