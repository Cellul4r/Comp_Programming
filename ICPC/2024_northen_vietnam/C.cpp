#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef vector<int> vi;
typedef vector<ll> vl;

#define rep(i, a) for(int i=0;i<a;++i)
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define trav(a,x) for (auto& a : x)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
//#define f first
//#define s second
#define lb lower_bound
#define ub upper_bound

const char nl = '\n';
const int N =1e6+1;
const int INF = 1e9+7;
const long long LINF = 1e18+7;

int n,m,k;
void addS(int& a, int b) {
    a += b;
    if(a >= k) a -= k;
    if(a < 0) a += k;
}
ll cnt[1000002];
vector<vi> a;
vector<vl> p;
void solve(){

    cin>>n>>m;
    cin>>k;
    if(n <= m) {
        a.assign(n+1, vi(m+1));
        rep(i,n) rep(j,m) cin>>a[i+1][j+1];
    } else {
        a.assign(m+1, vi(n+1));
        rep(i,n) rep(j,m) cin>>a[j+1][i+1];
        swap(n,m);
    }
    
    // row n column m
    p.assign(n+3, vl(m+3));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            p[i][j] = p[i-1][j] + a[i][j];
            addS(a[i][j], a[i-1][j]);
        }
    }
    //dbg(p);
    ll ans = -LINF;
    memset(cnt, 0x3f, sizeof cnt);
    for(int left=1;left<=n;left++) {
        for(int right=left;right<=n;right++) {
            int now = 0;
            ll sum = 0;
            cnt[now] = sum;
            for(int i=1;i<=m;i++) {
                int x = a[right][i];
                addS(x, -a[left-1][i]);
                ll val = p[right][i] - p[left-1][i];
                addS(now,x);
                //dbg(val);
                sum += val;
                ans = max(ans, sum - cnt[now]);
                cnt[now] = min(cnt[now], sum);
                //dbg(left,right,sum,i);
            }

            now = 0;
            cnt[now] = 1e18;
            for(int i=1;i<=m;i++) {
                int x = a[right][i];
                addS(x, -a[left-1][i]);
                addS(now,x);
                cnt[now] = 1e18;
            }
        }

    }
    cout << ans;
}
/*
 *
6 7 5
1 2 0 0 3 3 1
3 0 3 1 0 1 2
1 1 0 2 0 3 2
2 4 1 4 4 0 3
0 2 3 0 2 2 1
0 0 3 0 1 0 4
 *
 */
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t = 1;
    //#ifndef ONLINE_JUDGE
    //   freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
    //#endif
    // cin>>t;
    while(t--)solve();
}
