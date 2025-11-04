/*
 *   author : cellul4r
 */
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
#define all(x) x.begin(), x.end()
const char nl = '\n';
const int N =2e5+1;
const int INF = 1e9+7;
const ll LINF = 1e18+7;

void setIO(string);
struct DSU {
    
    int rnk[N];
    int par[N];

    void init(int n) {
        for(int i = 0; i < n; i++) {
            rnk[i] = 1;
            par[i] = i;
        }
    }

    int findPar(int u) {
        if(u == par[u]) return u;
        return par[u] = findPar(par[u]);
    }

    void merge(int u, int v) {
        u = findPar(u);
        v = findPar(v);
        if(u == v) return;
        if(rnk[u] < rnk[v]) {
            par[u] = v;
            rnk[v] += rnk[u];
        } else {
            par[v] = u;
            rnk[u] += rnk[v];
        }
    }
};
void solve(){
    int n;
    string s;
    cin>>n>>s;

    DSU dsu;
    dsu.init(2*n);
    stack<int> st;
    for(int i = 0; i < 2*n; i++) {
        if(s[i] == ')') {
            dsu.merge(st.top(), i);
            st.pop();
        } else {
            if(i > 0 && s[i-1] == ')') {
                dsu.merge(i,i-1);
            }
            st.push(i);
        }
    }

    set<int> save;
    for(int i = 0; i < 2 * n; i++) {
        save.insert(dsu.findPar(i));
    }
    cout << save.size() << nl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    //setIO("");
    cin>>t;
    while(t--)solve();

    return 0;
}

void setIO(string s) {
    (void)!freopen((s + ".in").c_str(), "r", stdin);
    (void)!freopen((s + ".out").c_str(), "w", stdout);
}

